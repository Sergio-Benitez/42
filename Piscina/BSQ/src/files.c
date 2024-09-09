/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:45:19 by labderra          #+#    #+#             */
/*   Updated: 2024/03/21 13:56:36 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_keyb_entry(void)
{
	int		i;
	char	*c;
	int		bytes_read;

	i = 0;
	bytes_read = 1;
	c = malloc(256);
	if (c == NULL)
		ft_error("Error\n");
	while (bytes_read > 0)
	{
		bytes_read = read(0, &c[i], 1);
		i++;
		if (bytes_read > 0)
		{
			if (c[i - 1] == '\n')
			{
				c[i - 1] = '\0';
				break ;
			}
		}
	}
	return (c);
}

int	ft_file_size(char *str, int *n_lines)
{
	char	c;
	int		s;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Error\n");
	s = 1;
	*n_lines = 0;
	i = 0;
	while (s > 0)
	{
		s = read(fd, &c, 1);
		if (c == '\n')
			*n_lines = *n_lines + 1;
		i++;
	}
	close(fd);
	return (i);
}

int	ft_file_load(char *str, char *map)
{
	int	fd;
	int	s;
	int	n_lines;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Error\n");
	s = read(fd, map, ft_file_size(str, &n_lines));
	close(fd);
	return (s);
}
