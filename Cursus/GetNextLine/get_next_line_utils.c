/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:44:31 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/05 11:55:45 by sbenitez         ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
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

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
		return ((free(ptr)), NULL);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return ((free(ptr)), NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
