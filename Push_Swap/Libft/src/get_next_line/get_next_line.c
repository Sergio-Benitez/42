/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:37:37 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:22:33 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"
#include "../../inc/libft.h"

char	*ft_joinfree(char *buffer, char *aux)
{
	char	*temp;

	temp = ft_strjoin(buffer, aux);
	free(buffer);
	return (temp);
}

char	*ft_readbuffer(int fd, char *buffer)
{
	int		i;
	char	*aux;

	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while ((!ft_strchr(aux, '\n')) && i > 0)
	{
		i = read(fd, aux, BUFFER_SIZE);
		if (i == -1)
			return (free(aux), NULL);
		aux[i] = '\0';
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
	line = ft_calloc(i + 1 + (buffer[i] == '\n'), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
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
	static char	*buffer[FD_SETSIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_readbuffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_readline(buffer[fd]);
	buffer[fd] = ft_updatebuffer(buffer[fd]);
	return (line);
}
