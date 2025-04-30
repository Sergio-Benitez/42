/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:52:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/30 20:02:50 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_fill_cmd(t_shell *shell)
{
	int		i;
	t_cmd	*temp;

	i = 0;
	temp = shell->cmd_lst;
	while (temp->next)
		temp = temp->next;
	if (!temp->args)
		temp->args = ft_calloc(sizeof(char *), (ft_count_args(shell->token) + 1));
	else
		while (temp->args[i])
			i++;
	while (shell->token && shell->token->type == WORD)
	{
		if (shell->token->tkn)
			temp->args[i] = ft_strdup(shell->token->tkn);
		i++;
		if (shell->token->next && shell->token->next->type == WORD)
			shell->token = shell->token->next;
		else
			break ;
	}
	if (ft_isbuiltin(temp->args[0]))
		temp->is_btn = 1;
}

int	ft_get_commands(t_shell *shell)
{
	t_token	*temp;

	temp = shell->token;
	ft_addback_cmd(&shell->cmd_lst);
	while (temp)
	{
		if (temp->type == PI)
			ft_addback_cmd(&shell->cmd_lst);
		else if (temp->type == WORD)
			ft_fill_cmd(shell);
		temp = temp->next;
	}
	return (1);
}
