/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:55:13 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/02 21:36:45 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_intstrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	if ((char)c == '\0')
		return (-1);
	return (-1);
}

int	ft_find_end(char *tkn)
{
	int	i;

	i = 0;
	while (tkn[i] != '<' && tkn[i] != '>' && tkn[i] != '|' && tkn[i] != ' '
		&& tkn[i] != '\0' && tkn[i] != '$' && tkn[i] != '\'' && tkn[i] != '\"')
		i++;
	return (i);
}

t_xpnd	*ft_init_expand(void)
{
	t_xpnd	*xpnd;

	xpnd = safe_malloc(sizeof (t_xpnd));
	xpnd->start = -1;
	xpnd->end = -1;
	xpnd->var = NULL;
	xpnd->value = NULL;
	return (xpnd);
}

char	*ft_substr_malloc(const char *input, int start, int len)
{
	char	*substr;

	if (!input || start < 0 || len < 0)
		return (NULL);
	substr = safe_malloc(sizeof(char) * (len + 1));
	ft_strlcpy(substr, &input[start], len);
	return (substr);
}

void	ft_free_expand(t_xpnd *xpnd)
{
	if (xpnd)
	{
		if (xpnd->var)
			free(xpnd->var);
		if (xpnd->value)
			free(xpnd->value);
		free(xpnd);
		xpnd = NULL;
	}
}
