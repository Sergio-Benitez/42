/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:09:38 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/13 19:08:35 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_process_input(t_cmd *cmd, t_token *token)
{
	if (cmd->infile)
		free(cmd->infile);
	cmd->infile = ft_strdup(token->next->tkn);
	if (!cmd->infile)
		return ;
	if (access(cmd->infile, R_OK) == -1)
	{
		cmd->exit_status = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->infile, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void	ft_process_output(t_cmd *cmd, t_token *token)
{
	int	fd;

	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = ft_strdup(token->next->tkn);
	if (!cmd->outfile)
		return ;
	cmd->append = false;
	fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		cmd->exit_status = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->outfile, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else
	{
		if (close(fd) == -1)
		{
			cmd->exit_status = 1;
			ft_putstr_fd("minishell: Error closing file\n", 2);
		}
	}
}

void	ft_process_append(t_cmd *cmd, t_token *token)
{
	int	fd;

	if (cmd->outfile)
		free(cmd->outfile);
	cmd->outfile = ft_strdup(token->next->tkn);
	if (!cmd->outfile)
		return ;
	cmd->append = true;
	fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		cmd->exit_status = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->outfile, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else
	{
		if (close(fd) == -1)
		{
			cmd->exit_status = 1;
			ft_putstr_fd("minishell: Error closing file\n", 2);
		}
	}
}

void	ft_process_heredoc(t_cmd *cmd, t_token *token)
{
	if (cmd->delimiter)
		free(cmd->delimiter);
	cmd->delimiter = ft_strdup(token->next->tkn);
	if (!cmd->delimiter)
		return ;
	cmd->hd = true;
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
		if (temp->exit_status == 1)
			shell->exit_status = 1;
		else
			shell->exit_status = 0;
		*next_tkn = token->next->next;
	}
	else
		*next_tkn = token->next;
}
