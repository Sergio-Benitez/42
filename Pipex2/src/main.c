/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:01 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/10 17:33:32 by sbenitez         ###   ########.fr       */
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
	write(2, "Command not found: ", 19);
	write(2, argv, ft_strlen(argv));
	write(2, "\n", 1);
	exit(127);
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

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(1, "The argument number must be 4", 29);
		exit(1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("Pipe error");
		exit (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	if (pid == 0)
		child(pipefd, argv, env);
	else
		parent(pipefd, argv, env);
	return (0);
}
