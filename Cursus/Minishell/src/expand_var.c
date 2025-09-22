/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:16:26 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/29 16:16:23 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_getenv(char **env, char *var)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var))
			&& env[i][ft_strlen(var)] == '=')
			return (ft_strdup(&env[i][ft_strlen(var) + 1]));
		i++;
	}
	return (NULL);
}

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

void	ft_insert_exp(t_xpnd *xpnd, t_token *t)
{
	char		*res;
	int			i;
	size_t		j;

	res = safe_malloc(ft_strlen(t->tkn) - (xpnd->end - xpnd->start + 1)
			+ ft_strlen(xpnd->value) + 1);
	i = -1;
	j = -1;
	while (++i < xpnd->start - 1)
		res[i] = t->tkn[i];
	while (++j < ft_strlen(xpnd->value))
	{
		res[i] = xpnd->value[j];
		i++;
	}
	j = xpnd->end;
	while (t->tkn[j])
		res[i++] = t->tkn[j++];
	free(xpnd->value);
	xpnd->value = NULL;
	res[i] = '\0';
	free(t->tkn);
	t->tkn = res;
}

void	ft_expand_token(t_shell *shell, t_token *token)
{
	t_xpnd	*xpnd;

	xpnd = ft_init_expand();
	while (token->tkn[0] && ft_strchr(token->tkn, '$')
		&& token->tkn[ft_intstrchr(token->tkn, '$')] != ' '
		&& token->tkn[ft_intstrchr(token->tkn, '$')] != '\"')
	{
		xpnd->start = ft_intstrchr(token->tkn, '$');
		if (token->tkn[xpnd->start] == '?')
		{
			ft_expand_exitstatus(shell, token);
			continue ;
		}
		xpnd->end = xpnd->start + ft_find_end(&token->tkn[xpnd->start]);
		xpnd->var = ft_substr_malloc(token->tkn, xpnd->start,
				(xpnd->end - xpnd->start + 1));
		xpnd->value = ft_getenv(shell->env, xpnd->var);
		free(xpnd->var);
		xpnd->var = NULL;
		if (!xpnd->value)
			xpnd->value = ft_strdup("");
		ft_insert_exp(xpnd, token);
	}
	ft_free_expand(xpnd);
}

void	ft_expand_var(t_shell *shell)
{
	t_token	*temp;

	temp = shell->token;
	while (temp)
	{
		if (temp->expand == true)
			ft_expand_token(shell, temp);
		temp = temp->next;
	}
}
