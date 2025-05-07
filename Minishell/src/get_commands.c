/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:52:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/07 13:07:39 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_fill_cmd(t_shell *shell, t_token *token, t_token **next_token)
{
	int		i;
	t_cmd	*temp;

	i = 0;
	temp = shell->cmd_lst;
	while (temp->next)
		temp = temp->next;
	if (!temp->args)
		temp->args = ft_calloc(sizeof(char *), (ft_count_args(token) + 1));
	else
		while (temp->args[i])
			i++;
	while (token && token->type == WORD)
	{
		if (token->tkn)
			temp->args[i++] = ft_strdup(token->tkn);
		*next_token = token->next;
		if (token->next && token->next->type == WORD)
			token = token->next;
		else
			break ;
	}
	if (ft_isbuiltin(temp->args[0]))
		temp->is_btn = 1;
}

void	ft_process_token(t_shell *shell, t_token **temp)
{
	t_token	*next;

	if ((*temp)->type == PI)
	{
		ft_addback_cmd(&shell->cmd_lst);
		*temp = (*temp)->next;
	}
	else if ((*temp)->type == WORD)
	{
		ft_fill_cmd(shell, *temp, &next);
		*temp = next;
	}
	else if ((*temp)->type == LR1 || (*temp)->type == RR1
		|| (*temp)->type == LR2 || (*temp)->type == RR2)
	{
		ft_process_redir(shell, *temp, &next);
		*temp = next;
	}
	else
		*temp = (*temp)->next;
}

int	ft_has_commands(t_shell *shell)
{
	t_cmd	*cmd;

	if (!shell || !shell->cmd_lst)
		return (0);
	cmd = shell->cmd_lst;
	while (cmd)
	{
		if (cmd->args && cmd->args[0])
			return (1);
		cmd = cmd->next;
	}
	return (0);
}

int	ft_get_commands(t_shell *shell)
{
	t_token	*temp;

	temp = shell->token;
	ft_addback_cmd(&shell->cmd_lst);
	while (temp)
		ft_process_token(shell, &temp);
	if (!ft_has_commands(shell))
		return (0);
	return (1);
}
