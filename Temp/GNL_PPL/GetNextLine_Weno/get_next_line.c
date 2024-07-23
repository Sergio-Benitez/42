/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:58:32 by gmontoro          #+#    #+#             */
/*   Updated: 2024/07/23 11:33:36 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *buffer, char *aux)
{
	char	*temp;

	temp = ft_strjoin(buffer, aux);
	free(buffer);
	return (temp);
}

char	*ft_readbuffer(char *buffer, int fd)
{
	int		cnt;
	char	*aux;

	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	aux = ft_calloc(BUFFER_SIZE + 1, 1);
	cnt = 1;
	while ((!ft_strchr(aux, '\n')) && cnt > 0)
	{
		cnt = read(fd, aux, BUFFER_SIZE);
		if (cnt == -1)
			return (free(aux), NULL);
		aux[cnt] = '\0';
		buffer = ft_joinfree(buffer, aux);
		if (!buffer)
			return (NULL);
	}
	free(aux);
	return (buffer);
}

char	*ft_readline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 1 + (buffer[i] == '\n'), 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_updatebuffer(char *buffer)
{
	int		i;
	int		j;
	char	*upt;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free(buffer));
	upt = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!upt)
		return (ft_free(buffer));
	i++;
	j = 0;
	while (buffer[i])
		upt[j++] = buffer[i++];
	free(buffer);
	return (upt);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_readbuffer(buffer, fd);
	if (!buffer)
		return (ft_free(buffer));
	line = ft_readline(buffer);
	buffer = ft_updatebuffer(buffer);
	return (line);
}
