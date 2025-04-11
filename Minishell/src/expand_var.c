/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:16:26 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/11 20:41:14 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_find_dollar(t_shell *shell)
{
	t_token	*temp;
	int		flag;

	temp = shell->token;
	flag = 0;
	while (temp)
	{
		if ((ft_strchr(temp->tkn, '$') != 0) && (temp->type != 1))
		{
			temp->expand = true;
			flag = 1;
		}
		temp = temp->next;
	}
	return (flag);
}

int	ft_find_end(char *tkn)
{
	int	i;

	i = 0;
	while (tkn[i] != '<' && tkn[i] != '>' && tkn[i] != '|' && tkn[i] != ' '
		&& tkn[i] != '\0' && tkn[i] != '$' && tkn[i] != '\'')
			i++;
	return (i);
}

/* void	ft_expand_this(t_shell *shell, t_token *token)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (token->tkn[i] && ft_strchr(token->tkn, '$')
			&& token->tkn[ft_cntstrchr(token->tkn, '$') + 1] != ' ')
	{
		start = ft_cntstrchr(token->tkn, '$');
		end = ft_find_end(&token->tkn[start]);
		// ft_getenv -> struct
		// ft_strlen_definitivo(string + ft_getenv - (end + start +1)
		// new_str = char *ft_my_strcpy(char *token->tkn, start, char *ft_getenv)
		// free(token->tkn)
		// token->tkn = new_str;
	}
} */

void	ft_expand_var(t_shell *shell)
{
	t_token	*temp;

	temp = shell->token;
	while (temp)
	{
		if (temp->expand == true)
//			ft_expand_this(shell, temp);
		temp = temp->next;
	}
}