/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:23:35 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/07 13:29:35 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_redir_tkn(t_shell *shell, int *i)
{
	if (shell->input[*i] == '<')
	{
		if (shell->input[*i +1] == '<')
		{
			ft_addback_tkn(&shell->token, "<<", 7);
			*i += 2;
			return ;
		}
		ft_addback_tkn(&shell->token, "<", 6);
		*i += 1;
	}
	else if (shell->input[*i] == '>')
	{
		if (shell->input[*i +1] == '>')
		{
			ft_addback_tkn(&shell->token, ">>", 5);
			*i += 2;
			return ;
		}
		ft_addback_tkn(&shell->token, ">", 4);
		*i += 1;
	}
}

void	ft_word_tkn(t_shell *shell, int *i)
{
	char	*token;
	int		j;

	j = *i;
	while (shell->input[j] != 34 && shell->input[j] != '<'
		&& shell->input[j] != '>' && shell->input[j] != '|'
		&& shell->input[j] != ' ' && shell->input[j] != '\0')
		j++;
	token = ft_substr(shell->input, *i, (j - *i));
	ft_addback_tkn(&shell->token, token, 0);
	if (shell->input[j] != '\0' && shell->input[j] != '<'
		&& shell->input[j] != '>' && shell->input[j] != '|'
		&& shell->input[j] != ' ')
		ft_update_join(&shell->token);
	free(token);
	*i = j;
}

void	ft_tokenize(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->input[i])
	{
		if (shell->input[i] == ' ' || shell->input[i] == '\t')
			i++;
		else if (shell->input[i] == '\'' || shell->input[i] == '"')
		{
			if (!ft_quotes(shell, &i))
				break ;
		}
		else if (shell->input[i] == '<' || shell->input[i] == '>')
			ft_redir_tkn(shell, &i);
		else if (shell->input[i] == '|')
		{
			ft_addback_tkn(&shell->token, "|", 3);
			i++;
		}
		else
			ft_word_tkn(shell, &i);
	}
}
