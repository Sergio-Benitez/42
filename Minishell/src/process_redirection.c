/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:09:38 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/02 21:41:31 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_process_input(t_cmd *cmd, t_token *token)
{
	if (cmd->infile)
		free(cmd->infile);
	cmd->infile = ft_strdup(token->next->tkn);
	// Nota: bash verifica que el archivo exista, pero no lo crea
	// La verificación se hará en el momento de la ejecución (?)
}

void	ft_process_output(t_cmd *cmd, t_token *token)
{
	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = ft_strdup(token->next->tkn);
	cmd->append = 0;
	// Nota: bash crea el archivo si no existe, o lo trunca si ya existe
	// La creación se hará en el momento de la ejecución (?)
}

void	ft_process_append(t_cmd *cmd, t_token *token)
{
	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = ft_strdup(token->next->tkn);
	cmd->append = 1;
	// Nota: bash crea el archivo si no existe, o añade al final si ya existe
	// La creación/apertura se hará en el momento de la ejecución (?)
}

void	ft_process_heredoc(t_cmd *cmd, t_token *token)
{
	if (cmd->delimiter)
		free(cmd->delimiter);
	cmd->hd = 1;
	cmd->delimiter = ft_strdup(token->next->tkn);
	// Nota: heredoc se procesará durante la ejecución (?)
}

void	ft_process_redir(t_shell *shell, t_token *token, t_token **next_tkn)
{
	t_cmd	*temp;

	temp = shell->cmd_lst;
	while (temp->next)
		temp = temp->next;
	if (token->next && token->next->type == WORD)
	{
		if (token->type == LR1)
			ft_process_input(temp, token);
		else if (token->type == RR1)
			ft_process_output(temp, token);
		else if (token->type == RR2)
			ft_process_append(temp, token);
		else if (token->type == LR2)
			ft_process_heredoc(temp, token);
		*next_tkn = token->next->next;
	}
	else
		*next_tkn = token->next;
}
