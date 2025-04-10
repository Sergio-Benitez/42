/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tknize_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:52:27 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/10 18:52:11 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_dquote_tkn(t_shell *shell, int *i)
{
	char	*token;
	int		j;
	int		flag;

	j = *i + 1;
	flag = 0;
	while (shell->input[j])
	{
		if (shell->input[j] == 34)
		{
			flag = 1;
			token = ft_substr(shell->input, *i, (j - *i) + 1);
			ft_addback_tkn(&shell->token, token, 2);
			if (shell->input[j + 1] == 34)
				ft_update_join(&shell->token);
			free(token);
			break ;
		}
		j++;
	}
	*i = j + 1;
	if (flag == 0)
		return (printf("Error: quotes must be closed\n"), 0);
	return (1);
}

int	ft_squote_tkn(t_shell *shell, int *i)
{
	char	*token;
	int		j;
	int		flag;

	j = *i + 1;
	flag = 0;
	while (shell->input[j])
	{
		if (shell->input[j] == 39)
		{
			flag = 1;
			token = ft_substr(shell->input, *i, (j - *i) + 1);
			ft_addback_tkn(&shell->token, token, 1);
			if (shell->input[j + 1] == 39)
				ft_update_join(&shell->token);
			free(token);
			break ;
		}
		j++;
	}
	*i = j + 1;
	if (flag == 0)
		return (printf("Error: quotes must be closed\n"), 0);
	return (1);
}

int	ft_quotes(t_shell *shell, int *i)
{
	if (shell->input[*i] == 34)
	{
		if (!ft_dquote_tkn(shell, i))
		{
			shell->exit_status = 1;
			ft_free_tknlst(&shell->token);
			return (0);
		}
	}
	else if (shell->input[*i] == 39)
	{
		if (!ft_squote_tkn(shell, i))
		{
			shell->exit_status = 1;
			ft_free_tknlst(&shell->token);
			return (0);
		}
	}
	return (1);
}

void	ft_join_qtoken(t_shell *shell)
{
	t_token	*curr;
	t_token	*next;
	char	*joined;

	curr = shell->token;
	while (curr && curr->next)
	{
		next = curr->next;
		if (curr->join == true && curr->type == next->type)
		{
			joined = ft_strjoin(curr->tkn, next->tkn);
			free(curr->tkn);
			curr->tkn = joined;
			curr->join = next->join;
			curr->next = next->next;
			free(next->tkn);
			free(next);
		}
		else
			curr = curr->next;
	}
}
