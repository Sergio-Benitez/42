/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tknize_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:52:27 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/09 19:20:47 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_dquote_tkn(t_shell *shell, int *i)
{
	char	*input;
	char	*token;
	int		j;
	int		flag;

	input = shell->input;
	j = *i + 1;
	flag = 0;
	while (input[j])
	{
		if (input[j] == 34)
		{
			flag = 1;
			token = ft_substr(input, *i, (j - *i) + 1);
			ft_addback_tkn(&shell->token, token, 2);
			free(token);
			break ;
		}
		j++;
	}
	*i = j;
	if (flag == 0)
		return (printf("Error: quotes must be closed\n"), 0);
	return (1);
}

int	ft_squote_tkn(t_shell *shell, int *i)
{
	char	*input;
	char	*token;
	int		j;
	int		flag;

	input = shell->input;
	j = *i + 1;
	flag = 0;
	while (input[j])
	{
		if (input[j] == 39)
		{
			flag = 1;
			token = ft_substr(input, *i, (j - *i) + 1);
			ft_addback_tkn(&shell->token, token, 1);
			free(token);
			break ;
		}
		j++;
	}
	*i = j;
	if (flag == 0)
		return (printf("Error: quotes must be closed\n"), 0);
	return (1);
}

int	ft_quotes(t_shell *shell, int *i)
{
	if (shell->input[*i] == 34)
	{
		if (!ft_dquote_tkn(shell, i))
			return (0);
	}
	else if (shell->input[*i] == 39)
	{
		if (!ft_squote_tkn(shell, i))
			return (0);
	}
	return (1);
}
