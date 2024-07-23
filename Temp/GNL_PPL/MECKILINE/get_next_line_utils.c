/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:46:09 by labderra          #+#    #+#             */
/*   Updated: 2024/05/02 11:58:44 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	ptr = (char *)dst;
	while (src <= dst && len--)
		ptr[len] = ((char *)src)[len];
	while (src > dst && i < len)
	{
		ptr[i] = ((char *)src)[i];
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = count * size;
	p = malloc(i);
	if (!p)
		return (NULL);
	while (i-- > 0)
		p[i] = 0;
	return ((void *)p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	size;

	if (start >= ft_strlen(s))
		size = 0;
	else if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
