/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:51:39 by jormoral          #+#    #+#             */
/*   Updated: 2024/06/10 19:36:55 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freejoin(char *sbuffer, char *aux)
{
	char	*temp;

	temp = ft_strjoin(sbuffer, aux);
	free (sbuffer);
	return (temp);
}

char	*ft_read_buffer(char *sbuffer, int fd)
{
	int		byte;
	char	*aux;

	if (!sbuffer)
	{
		sbuffer = ft_calloc(1, 1);
		if (!sbuffer)
			return (NULL);
	}
	aux = ft_calloc(BUFFER_SIZE + 1, 1);
	byte = 1;
	while ((!ft_strchr(aux, '\n')) && byte > 0)
	{
		byte = read(fd, aux, BUFFER_SIZE);
		if (byte == -1)
			return (free(aux), NULL);
		aux[byte] = '\0';
		sbuffer = ft_freejoin(sbuffer, aux);
		if (!sbuffer)
			return (NULL);
	}
	free (aux);
	return (sbuffer);
}

char	*ft_read_line(char *sbuffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!sbuffer[i])
		return (NULL);
	while (sbuffer[i] != '\n' && sbuffer[i] != '\0')
		i++;
	line = (char *)ft_calloc(i + 1 + (sbuffer[i] == '\n'), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (sbuffer[i] != '\n' && sbuffer[i] != '\0')
	{
		line[i] = sbuffer[i];
		i++;
	}
	if (sbuffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_updatebuffer(char *sbuffer)
{
	int		i;
	int		j;
	char	*update;

	i = 0;
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	if (!sbuffer[i])
		return (ft_free(sbuffer));
	update = ft_calloc ((ft_strlen(sbuffer) - i + 1), sizeof(char));
	if (!update)
		return (ft_free(sbuffer));
	i++;
	j = 0;
	while (sbuffer[i])
		update[j++] = sbuffer[i++];
	free (sbuffer);
	return (update);
}

char	*get_next_line(int fd)
{
	static char	*sbuffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	sbuffer = ft_read_buffer(sbuffer, fd);
	if (!sbuffer)
		return (ft_free(sbuffer));
	line = ft_read_line(sbuffer);
	sbuffer = ft_updatebuffer(sbuffer);
	return (line);
}
