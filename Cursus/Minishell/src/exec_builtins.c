/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:44:32 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 14:44:58 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	execute_builtin(t_shell *ms, t_cmd *cmd, int prevfd)
{
	if (!cmd->args[0])
		cmd->args[0] = ft_strdup("");
	if (!ft_strncmp(cmd->args[0], "echo", 5))
		ms->exit_status = exec_echo(cmd);
	else if (!ft_strncmp(cmd->args[0], "cd", 3))
		ms->exit_status = exec_cd(ms, cmd);
	else if (!ft_strncmp(cmd->args[0], "pwd", 4))
		ms->exit_status = exec_pwd();
	else if (!ft_strncmp(cmd->args[0], "export", 7))
		ms->exit_status = exec_export(ms, cmd);
	else if (!ft_strncmp(cmd->args[0], "unset", 6))
		ms->exit_status = exec_unset(ms, cmd);
	else if (!ft_strncmp(cmd->args[0], "env", 4))
		ms->exit_status = exec_env(ms);
	else if (!ft_strncmp(cmd->args[0], "exit", 5))
		exec_exit(ms, cmd, prevfd);
	else
		return ;
}
