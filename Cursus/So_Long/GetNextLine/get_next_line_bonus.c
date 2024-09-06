/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:37:37 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/23 18:47:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("mama.txt", O_RDONLY);
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd1);
	}
	free(line);
	close(fd1);
	
	fd2 = open("papa.txt", O_RDONLY);
	line = get_next_line(fd2);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd2);
	}
	free(line);
	close(fd2);

	fd3 = open("jorgito.txt", O_RDONLY);
	line = get_next_line(fd3);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd3);
	}
	free(line);
	close(fd3);
	return (0);
}*/