/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:06:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/27 13:21:12 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_cmd_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->args)
		return ;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		cmd->args[i] = NULL;
		i++;
	}
	free(cmd->args);
	cmd->args = NULL;
}

void	ft_free_cmd_files(t_cmd *cmd)
{
	if (cmd->infile)
		free(cmd->infile);
	if (cmd->outfile)
		free(cmd->outfile);
	if (cmd->delimiter)
		free(cmd->delimiter);
}
