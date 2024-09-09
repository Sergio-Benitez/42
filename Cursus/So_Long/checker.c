/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:52:30 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/10 01:49:42 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i] != 'r' || name[i - 1] != 'e' || name[i - 2] != 'b'
		|| name[i - 4] == '\0')
	{
		write(2, "Error\nInappropriate map format.\n", 32);
		exit (1);
	}
	return (1);
}

int	check_frame(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < map->width)
	{
		if (map->data[0][x] != '1' || map->data[map->height - 1][x] != '1')
			return (write(2, "falla x.\n", 9), 0);
		x++;
	}
	while (y < map->height)
	{
		if (map->data[y][0] != '1' || map->data[y][map->width - 1] != '1')
			return (write(2, "falla y.\n", 9), 0);
		y++;
	}
	return (1);
}

int	check_chars(t_map *map)
{
	int	zero;
	int	one;
	int	c;
	int	e;
	int	p;

	return (0);
}
