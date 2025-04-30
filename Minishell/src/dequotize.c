/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequotize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:31:47 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/30 18:56:49 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_remove_quotes(char *tkn)
{
	char	*new_tkn;
	int		i;
	int		j;
	char	quote;

	new_tkn = safe_malloc(ft_strlen(tkn) + 1);
	i = 0;
	j = 0;
	while (tkn[i])
	{
		if (tkn[i] == '\'' || tkn[i] == '\"')
		{
			quote = tkn[i++];
			while (tkn[i] && tkn[i] != quote)
				new_tkn[j++] = tkn[i++];
			if (tkn[i] == quote)
				i++;
		}
		else
			new_tkn[j++] = tkn[i++];
	}
	new_tkn[j] = '\0';
	return (new_tkn);
}

void	ft_dequotize(t_shell *shell)
{
	t_token	*temp;
	char	*new_tkn;

	temp = shell->token;
	while (temp)
	{
		if (temp->type == SQ || temp->type == DQ || temp->type == WORD)
		{
			new_tkn = ft_remove_quotes(temp->tkn);
			if (new_tkn)
			{
				free(temp->tkn);
				temp->tkn = new_tkn;
				temp->type = WORD;
			}
		}
		temp = temp->next;
	}
	ft_join_token(shell);
}
