/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:49:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/08 19:13:21 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pipe_syntax(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
}

int	ft_check_pipe(t_shell *shell)
{
	t_token	*temp;

	temp = shell->token;
	if (!temp)
		return (1);
	if (temp->type == PI)
	{
		ft_pipe_syntax();
		return (ft_free_tknlst(&shell->token), 0);
	}
	while (temp)
	{
		if (temp->type == PI && temp->next && temp->next->type == PI)
		{
			ft_pipe_syntax();
			return (ft_free_tknlst(&shell->token), 0);
		}
		if (temp->next == NULL && temp->type == PI)
		{
			ft_pipe_syntax();
			return (ft_free_tknlst(&shell->token), 0);
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_check_redir(t_shell *shell)
{
	t_token	*temp;

	temp = shell->token;
	if (!temp)
		return (1);
	while (temp)
	{
		if (temp->type > 3 && temp->type < 8)
		{
			if (!temp->next || temp->next->type > 2)
			{
				ft_putstr_fd("minishell: syntax error near redirection\n", 2);
				return (ft_free_tknlst(&shell->token), 0);
			}
		}
		temp = temp->next;
	}
	return (1);
}

void	ft_check_syntax(t_shell *shell)
{
	if (!ft_check_pipe(shell))
	{
		shell->exit_status = 2;
		return ;
	}
	if (!ft_check_redir(shell))
	{
		shell->exit_status = 2;
		return ;
	}
}
