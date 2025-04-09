/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:35:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/09 19:17:15 by sbenitez         ###   ########.fr       */
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
		}
		else
		{
			ft_addback_tkn(&shell->token, "<", 6);
			*i += 1;
		}
	}
	else if (shell->input[*i] == '>')
	{
		if (shell->input[*i +1] == '>')
		{
			ft_addback_tkn(&shell->token, ">>", 5);
			*i += 2;
		}
		else
		{
			ft_addback_tkn(&shell->token, ">", 4);
			*i += 1;
		}
	}
}

void	ft_tokenize(t_shell *shell)
{
    int		i;
 
	i = 0;
	while (shell->input[i])
	{
		while (shell->input[i] == ' ')
			i++;
		if (shell->input[i] == 34 || shell->input[i] == 39)
		{
			if (!ft_quotes(shell, &i))
				break ;
		}
		else if (shell->input[i] == '|')
		{
			ft_addback_tkn(&shell->token, "|", 3);
			i++;
		}
		else if (shell->input[i] == '<' || shell->input[i] == '>')
			ft_redir_tkn(shell, &i);
		else
			i++;
	}
	
}

void	ft_get_input(t_shell *shell)
{
	while ((shell->input = readline("minishell> ")) != NULL)
	{
		add_history(shell->input);
		ft_tokenize(shell);
		ft_print_tokens(shell->token);
		free(shell->input);
		if (shell->token != NULL)
			ft_free_tknlst(&shell->token);
	}
}
