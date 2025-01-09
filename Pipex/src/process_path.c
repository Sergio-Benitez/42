/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:25:29 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/09 18:34:06 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child(int *pipefd, char **argv, char **env)
{
	int	inputfd;

	close(pipefd[0]);
	inputfd = open(argv[1], O_RDONLY);
	if (inputfd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	if (dup2(inputfd, STDIN_FILENO) < 0)
	{
		perror("Error duplicating file descriptor");
		exit(1);
	}
	close(inputfd);
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
	{
		perror("Error duplicating file descriptor");
		exit(1);
	}
	run_cmd(argv[2], env);
}

void	parent(int *pipefd, char **argv, char **env)
{
	int	outputfd;

	close(pipefd[1]);
	wait(NULL);
	outputfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outputfd < 0)
	{
		perror("Error writing file");
		exit(1);
	}
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
	{
		perror("Error duplicating file descriptor");
		exit(1);
	}
	close(pipefd[0]);
	if (dup2(outputfd, STDOUT_FILENO) < 0)
	{
		perror("Error duplicating file descriptor");
		exit(1);
	}
	close(outputfd);
	run_cmd(argv[3], env);
}

char	*find_path(char *str, char **env, int len)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(str, env[i], len) == 0)
			break ;
		i++;
	}
	return (env[i]);
}

char	**split_path(char *path, int start)
{
	char	**sorted;
	int		i;

	i = 0;
	if (!path)
		return (ft_split(" ", ' '));
	sorted = ft_split(&path[start], ':');
	if (!sorted)
		return (NULL);
	while (sorted[i])
	{
		sorted[i] = ft_strjoin(sorted[i], "/");
		i++;
	}
	return (sorted);
}

char	*check_access(char **path_list, char *cmd)
{
	int	i;

	i = 0;
	while (path_list[i])
	{
		if (!cmd)
			return (NULL);
		path_list[i] = ft_strjoin(path_list[i], cmd);
		if ((access(path_list[i], X_OK)) == 0)
			break ;
		free (path_list[i]);
		path_list[i] = NULL;
		i++;
	}
	if (path_list[i] == NULL)
		return (NULL);
	return (path_list[i]);
}
