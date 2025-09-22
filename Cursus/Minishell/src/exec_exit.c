/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:06:24 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 17:52:28 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_exit(t_shell *ms)
{
	ft_cleanup_shell(ms);
	ft_clean(ms->env, NULL, ms);
}

void	exec_exit(t_shell *ms, t_cmd *cmd, int prevfd)
{
	int	status;

	status = 0;
	if (cmd->args[1])
	{
		if (!ft_isnum(cmd->args[1]))
		{
			printf("exit\n");
			printf("minishell: exit: %s: numeric arg required\n", cmd->args[1]);
			free_exit(ms);
			exit(2);
		}
		status = (ft_atoi(cmd->args[1]) % 256);
		if (cmd->args[2])
		{
			printf("minishell: exit: too many arguments\n");
			ms->last_exit_st = 1;
			return ;
		}
	}
	if (prevfd == -1)
		printf("exit\n");
	free_exit(ms);
	exit((unsigned char)status);
}
