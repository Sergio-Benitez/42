/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:52:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/02 17:59:24 by sbenitez         ###   ########.fr       */
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

void ft_process_redirection(t_shell *shell, t_token *token, t_token **next_token)
{
    t_cmd *temp;

    temp = shell->cmd_lst;
    while (temp->next)
        temp = temp->next;
    // Primero verificamos que haya un token siguiente (nombre de archivo)
    if (token->next && token->next->type == WORD)
    {
        // Según el tipo de redirección, configuramos los campos correspondientes
        if (token->type == LR1) // <
        {
            temp->infile = ft_strdup(token->next->tkn);
        }
        else if (token->type == RR1) // >
        {
            temp->outfile = ft_strdup(token->next->tkn);
            temp->append = 0;
        }
        else if (token->type == RR2) // >>
        {
            temp->outfile = ft_strdup(token->next->tkn);
            temp->append = 1;
        }
        else if (token->type == LR2) // <<
        {
            temp->hd = 1;
			temp->delimiter = ft_strdup(token->next->tkn);
        }
        // Avanzamos dos tokens (la redirección y el nombre de archivo)
        *next_token = token->next->next;
    }
    else
    {
        // Si no hay un token de tipo WORD después de la redirección, 
        // solo avanzamos un token
        *next_token = token->next;
    }
}

int	ft_get_commands(t_shell *shell)
{
	t_token	*temp;
	t_token *next;

	temp = shell->token;
	ft_addback_cmd(&shell->cmd_lst);
	while (temp)
	{
		if (temp->type == PI)
		{
			ft_addback_cmd(&shell->cmd_lst);
			temp = temp->next;
		}
		else if (temp->type == WORD)
		{
			ft_fill_cmd(shell, temp, &next);
			temp = next;
		}
		else if (temp->type == LR1 || temp->type == RR1 || 
				temp->type == LR2 || temp->type == RR2)
		{
			ft_process_redirection(shell, temp, &next);
			temp = next;
		}
		else
			temp = temp->next;
	}
	return (1);
}
