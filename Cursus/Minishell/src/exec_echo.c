/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:22:07 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 18:05:05 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_check_flag(char *s)
{
	int	i;

	if (s[0] != '-')
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (i > 1);
}

int	do_echo(t_cmd *cmd)
{
	int	i;
	int	nl_flag;

	if (!cmd->args[1])
	{
		printf("\n");
		return (0);
	}
	i = 1;
	nl_flag = 1;
	while (cmd->args[i] && ft_check_flag(cmd->args[i]))
	{
		nl_flag = 0;
		i++;
	}
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (nl_flag)
		printf("\n");
	return (0);
}

int	exec_echo(t_cmd *cmd)
{
	int	fd;
	int	ret;

	if (cmd->exit_status == 1)
		return (1);
	fd = dup(STDOUT_FILENO);
	if (cmd->outfile)
		ft_redir_outfile(cmd->outfile, cmd->append);
	ret = do_echo(cmd);
	dup2(fd, STDOUT_FILENO);
	return (ret);
}
