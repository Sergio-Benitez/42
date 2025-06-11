/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:42:31 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 14:42:32 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_paths(char **paths, int i)
{
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	*ft_search_in_paths(char **paths, char *comm)
{
	char	*route;
	char	*tmp;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		route = ft_strjoin(tmp, comm);
		free(tmp);
		if (access(route, F_OK | X_OK) == 0)
		{
			free_paths(paths, i);
			return (route);
		}
		free(route);
		i++;
	}
	i = 0;
	free_paths(paths, i);
	return (NULL);
}

char	*ft_path(char *path, char **comm)
{
	char	**paths;

	if (ft_strchr(comm[0], '/'))
	{
		if (access(comm[0], F_OK | X_OK) == 0)
			return (ft_strdup(comm[0]));
		return (NULL);
	}
	if (!path)
		return (NULL);
	paths = ft_split(path + 5, ':');
	return (ft_search_in_paths(paths, comm[0]));
}

void	ft_handle_command_execution(t_shell *shell, t_cmd *cmd, char *path)
{
	int	i;

	i = 0;
	if (!path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd("\n", 2);
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
		exit(127);
	}
	execve(path, cmd->args, shell->env);
	perror("Error executing.\n");
	while (cmd->args && cmd->args[i])
		free(cmd->args[i++]);
	free(cmd->args);
	free(path);
	exit(126);
}

void	execute_command(t_shell *shell, t_cmd *cmd)
{
	int		i;
	char	*path;
	char	**env;

	i = 0;
	env = shell->env;
	if (!cmd->args || !cmd->args[0])
	{
		ft_putstr_fd("Error: empty command\n", 2);
		exit(127);
	}
	if (cmd->args[0][0] == '\0')
	{
		ft_putstr_fd("minishell: command '' not found\n", 2);
		exit(127);
	}
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!ft_strchr(cmd->args[0], '/') && !(env[i]))
	{
		ft_putstr_fd("No PATH found\n", 2);
		exit(127);
	}
	path = ft_path((env[i]), cmd->args);
	ft_handle_command_execution(shell, cmd, path);
}
