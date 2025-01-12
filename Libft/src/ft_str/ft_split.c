/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:18:39 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:26:19 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	ft_wordcount(char *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	if (!ft_strlen(s))
		return (0);
	i = 0;
	count = s[i] != c;
	while (s[i])
	{
		count += (s[i] == c && s[i + 1] != c && s[i + 1] != '\0');
		i++;
	}
	return (count);
}

static int	ft_next_worlen(char const *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			return (count);
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	tab_index;
	char	**tab;

	tab = ft_calloc(ft_wordcount((char *)s, c) + 1, sizeof(char *));
	if (!tab || !s)
		return (NULL);
	i = 0;
	tab_index = 0;
	while (tab_index < ft_wordcount((char *)s, c))
	{
		while (s[i] == c)
			i++;
		tab[tab_index] = ft_substr(s, i, ft_next_worlen(s, i, c));
		if (!tab[tab_index])
		{
			while (tab_index > 0)
				free(tab[--tab_index]);
			free(tab);
			return (NULL);
		}
		i = i + ft_next_worlen(s, i, c) + 1;
		tab_index++;
	}
	return (tab);
}
