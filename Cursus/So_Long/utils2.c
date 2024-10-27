/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:48:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/27 23:24:23 by sbenitez         ###   ########.fr       */
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

mlx_image_t *get_weighted_random_wall_texture(t_game *game)
{
    int total_weight = 0;
    int i = 0;

    // Sumar los pesos totales
    while (i < NUM_WALL_TEXTURES)
    {
        total_weight += game->wall_weights[i];
        i++;
    }

    int random_value = rand() % total_weight;
    int cumulative_weight = 0;
    i = 0;

    // Seleccionar una textura basada en los pesos
    while (i < NUM_WALL_TEXTURES)
    {
        cumulative_weight += game->wall_weights[i];
        if (random_value < cumulative_weight)
        {
            return game->img_wall[i];
        }
        i++;
    }

    return game->img_wall[0]; // Fallback, no debería ocurrir
}
