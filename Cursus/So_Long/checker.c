/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:52:30 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/11 01:59:30 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_type(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i] != 'r' || name[i - 1] != 'e' || name[i - 2] != 'b'
		|| name[i - 4] == '\0')
	{
		write(2, "Error\nInappropriate map format.\n", 32);
		return (0);
	}
	return (1);
}

int	check_chars(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	c = map->data[y][x];
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
				return (write(2, "Error\nInvalid character.\n", 25), 0);
			if (c == 'P')
				map->player_n++;
			if (c == 'E')
				map->exit_n++;
			if (c == 'C')
				map->collect_n++;
			x++;
		}
		y++;
	}
	return (map->player_n == 1 && map->exit_n == 1 && map->collect_n >= 1);
}

int	check_rect(char **map_data)
{
	int		i;

	i = 0;
	while (map_data[i])
	{
		if (ft_strlen(map_data[0]) != ft_strlen(map_data[i]))
		{
			write(2, "Error\nRows must be the same length.\n", 36);
			return (0);
		}
		i++;
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
			return (write(2, "Error\nFrame is not properly closed.\n", 36), 0);
		x++;
	}
	while (y < map->height)
	{
		if (map->data[y][0] != '1' || map->data[y][map->width - 1] != '1')
			return (write(2, "Error\nFrame is not properly closed.\n", 36), 0);
		y++;
	}
	return (1);
}

int	check_path(t_map *map)
{
	return (1);
}
