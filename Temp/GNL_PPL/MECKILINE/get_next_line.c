/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:39:11 by labderra          #+#    #+#             */
/*   Updated: 2024/04/30 22:39:11 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_load(int fd, char *buffer, size_t *size)
{
	char	*p;
	int		bytes_loaded;

	p = (char *)calloc(sizeof(char), (*size + BUFFER_SIZE + 1));
	if (!p)
		return (NULL);
	bytes_loaded = read(fd, &p[*size], BUFFER_SIZE);
	if (bytes_loaded < 0)
	{
		*size = 0;
		return (free(p), free(buffer), NULL);
	}
	if (!buffer)
	{
		*size = bytes_loaded;
		return (p);
	}
	p = ft_memmove(p, buffer, *size);
	*size = ft_strlen(p);
	return (free(buffer), p);
}

static char	*gnl_init(int fd, char **buffer, size_t *size, size_t *i)
{
	if (read(fd, 0, 0) == -1)
		return (free(*buffer), *buffer = NULL, NULL);
	*i = 0;
	if (*buffer == NULL)
	{
		*size = 0;
		*buffer = gnl_load(fd, *buffer, size);
		if (!*buffer)
			return (NULL);
	}
	else
		*size = ft_strlen(*buffer);
	return (*buffer);
}

static char	*gnl_return(size_t i, char **buffer, size_t size)
{
	char	*p;
	char	*swp;

	if (size == 0)
		return (free(*buffer), *buffer = NULL, NULL);
	else if (i == size)
	{
		p = ft_substr(*buffer, 0, size);
		if (!p)
			return (free(*buffer), *buffer = NULL, NULL);
		return (free(*buffer), *buffer = NULL, p);
	}
	else
	{
		swp = ft_substr(*buffer, i + 1, size - i);
		p = ft_substr(*buffer, 0, i + 1);
		if (!p || !swp)
			return (free(p), free(swp), free(*buffer), *buffer = NULL, NULL);
		return (free(*buffer), *buffer = swp, p);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	size_t		i;
	size_t		size;

	if (!gnl_init(fd, &buffer, &size, &i))
		return (NULL);
	while (buffer[i] != '\n')
	{
		while (buffer[i] != '\n' && i < size)
			i++;
		if (i == size)
		{
			buffer = gnl_load(fd, buffer, &size);
			if (size == i || size == 0)
				break ;
		}
	}
	return (gnl_return(i, &buffer, size));
}
