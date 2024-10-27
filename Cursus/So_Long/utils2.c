/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:48:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/27 18:56:44 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map_data(char **data, int height, int width)
{
	char	**copy;
	int		y;
	int		x;

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	y = 0;
	while (y < height)
	{
		copy[y] = malloc(sizeof(char) * (width + 1));
		if (!copy[y])
			return (NULL);
		x = 0;
		while (x < width)
		{
			copy[y][x] = data[y][x];
			x++;
		}
		copy[y][x] = '\0';
		y++;
	}
	return (copy);
}

void	free_map_data(char **aux, int height)
{
	while (--height >= 0)
		free(aux[height]);
	free(aux);
}

void	update_flags(t_map *map)
{
	int	i;
	int j;

	i = 0;
	map->update_flags = malloc(map->height * sizeof(bool *));
	while (i < map->height)
	{
		map->update_flags[i] = malloc(map->width * sizeof(bool));
		j = 0;
		while (j < map->width)
		{
			map->update_flags[i][j] = true; // Inicializa todas las banderas a true
			j++;
		}
		i++;
	}
}