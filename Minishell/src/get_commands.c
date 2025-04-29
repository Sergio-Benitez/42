/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:52:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/29 19:26:22 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_fill_commands(t_shell *shell)
{
	
}

void	ft_get_commands(t_shell *shell)
{
	ft_addback_commands(&shell->cmd_lst);
	while (shell->token)
	{
		if (shell->token->type == PI)
			ft_addback_commands(&shell->cmd_lst);
		else if (shell->token->type == WORD)
			ft_fill_cmd(); //to do
		shell->token = shell->token->next;
	}
}
