/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:44:31 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/07 19:58:57 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;
	
	i = 0;
	result = malloc(count * size);
	if (!result)
	{
		while (i < size * count)
			result[i++] = 0;
	}
	return ((void *)result);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return (((char *)s));
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char			*join;
	unsigned int	i;
	unsigned int	j;
	
	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i] != '\0')
		join[i] = s1[i++];
	j = 0;
}