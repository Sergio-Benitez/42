/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:28:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/30 19:34:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		if (matrix[i])
			free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_free_tknlst(t_token **token)
{
	t_token	*temp;

	while (*token)
	{
		temp = (*token)->next;
		if ((*token)->tkn)
			free((*token)->tkn);
		free(*token);
		*token = temp;
	}
	*token = NULL;
}

void	ft_free_cmdlst(t_cmd **cmd_lst)
{
	t_cmd	*temp;

	while (*cmd_lst)
	{
		temp = (*cmd_lst)->next;
		if ((*cmd_lst)->args)
			ft_free_matrix((*cmd_lst)->args);
		if ((*cmd_lst)->infile)
			free((*cmd_lst)->infile);
		if ((*cmd_lst)->outfile)
			free((*cmd_lst)->outfile);
		if ((*cmd_lst)->delimiter)
			free((*cmd_lst)->delimiter);
		free(*cmd_lst);
		*cmd_lst = temp;
	}
	*cmd_lst = NULL;
}

void	ft_cleanup_shell(t_shell *shell)
{
    if (shell->input)
    {
        free(shell->input);
        shell->input = NULL;
    }
    if (shell->token)
    {
        ft_free_tknlst(&shell->token);
        shell->token = NULL;
    }
    if (shell->cmd_lst)
    {
        ft_free_cmdlst(&shell->cmd_lst);
        shell->cmd_lst = NULL;
    }
    shell->last_exit_st = shell->exit_status;
}

void	ft_clean(char **matrix, t_token *token, t_shell *shell)
{
	if (matrix)
		ft_free_matrix(matrix);
	if (token)
		ft_free_tknlst(&token);
	if (shell)
	{
		free(shell);
		shell = NULL;
	}
}
