/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:01 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/11 16:43:35 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_split(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_exit_error(char *argv)
{
	if (argv[0] == '\0')
		write(2, "permission denied: \n", 21);
	else
	{
		write(2, "command not found: ", 20);
		write(2, argv, ft_strlen(argv));
		write(2, "\n", 1);
		exit(127);
	}
}

void	run_cmd(char *argv, char **env)
{
	char	**path_list;
	char	**cmd;
	char	*cmd_path;

	path_list = split_path(find_path("PATH=", env, 4), 5);
	cmd = ft_split(argv, ' ');
	cmd_path = check_access(path_list, cmd[0]);
	if (!cmd_path)
	{
		free(cmd_path);
		free_split(path_list);
		path_list = split_path(find_path("PWD=", env, 3), 4);
		cmd_path = check_access(path_list, cmd[0]);
		if (!cmd_path)
		{
			free_split(path_list);
			free_split(cmd);
			free(cmd_path);
		}
	}
	if (cmd_path)
		execve(cmd_path, cmd, env);
	ft_exit_error(argv);
}

int	handle_child_exit(pid_t pid)
{
	int	status;
	int	exit_status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		return (exit_status);
	}
	else
		return (1);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	int		exit_status;
	pid_t	pid;

	if (argc != 5)
	{
		write(1, "The argument number must be 4", 29);
		exit(1);
	}
	if (pipe(pipefd) == -1)
		(perror("Pipe error"), exit (1));
	pid = fork();
	if (pid == -1)
		(perror("Fork error"), exit(1));
	if (pid == 0)
		child(pipefd, argv, env);
	else
	{
		exit_status = handle_child_exit(pid);
		if (exit_status != 0)
			return (exit_status);
		parent(pipefd, argv, env);
	}
	return (0);
}
