/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:52:30 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/12 02:17:39 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_type(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5 || ft_strncmp(name + len - 4, ".ber", 4) != 0)
		return (write(2, "Error\nInappropriate map format.\n", 32), 0);
	return (1);
}

int	check_chars(t_map *map)
{
	int	y;
	int	x;
	int	invalid;

	y = 0;
	invalid = 0;
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->data[y][x] == 'P')
				map->player_n++;
			else if (map->data[y][x] == 'E')
				map->exit_n++;
			else if (map->data[y][x] == 'C')
				map->collect_n++;
			else if (map->data[y][x] != '1' && map->data[y][x] != '0')
				invalid = 1;
		}
		y++;
	}
	if (invalid)
		return (write(2, "Error\nInvalid character(s).\n", 28), 0);
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
/*	char	**aux;

	aux = map->data;
	aux[map->player_y][map->player_x] = 'X';
	flood_fill(map, aux, map->player_y, map->player_x);

*/
	return (1);
}
