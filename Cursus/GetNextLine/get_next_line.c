/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:44:34 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/08 13:42:48 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_joinfree(char *buffer, char *aux)
{
	char	*temp;
	
	temp = ft_strjoin(buffer, aux);
	free(buffer);
	return (temp);
}

static char	*ft_readbuffer(char *buffer, int fd)
{
	int		bytes_read;
	char	*aux;

	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while ((!ft_strchr(aux, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, aux, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(aux), NULL);
		aux[bytes_read] = '\0';
		buffer = ft_joinfree(buffer, aux);
		if (!buffer)
			return (NULL);
	}
	free(aux);
	return (buffer);
}

static char	*ft_readline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 1 + (buffer[i] == '\n'), sizeof(char));
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

static char	*ft_updatebuffer(char *buffer)
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
	static char	*buffer[fd];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_readbuffer(buffer[fd], fd);
	if (!buffer[fd])
		return (ft_free(buffer[fd]));
	line = ft_readline(buffer[fd]);
	buffer[fd] = ft_updatebuffer(buffer[fd]);
	return (line);
}

#include <fcntl.h>
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}