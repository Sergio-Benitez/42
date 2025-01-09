/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:01 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/09 17:23:23 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

void	ft_exit_error(char *str)
{
	write(2, "Command not found: ", 19);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(127);
}

void	run_cmd(char *argv, char **env)
{
	char	**path_list;
	char	**cmd;
	char	*full_cmd;

	path_list = split_path(find_path("PATH=", env, 4), 5);
	cmd = ft_split(argv, ' ');
	full_cmd = check_access(path_list, cmd[0]);
	if (!full_cmd)
	{
		free(full_cmd);
		free_split(path_list);
		path_list = split_path(find_path("PWD=", env, 3), 4);
		full_cmd = check_access(path_list, cmd[0]);
		if (!full_cmd)
		{
			free_split(path_list);
			free_split(cmd);
			free(full_cmd);
		}
	}
	if (full_cmd)
		execve(full_cmd, cmd, env);
	ft_exit_error(argv);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(1, "The argument number must be 5", 29);
		exit(1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("Pipe error");
		exit(1);
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
