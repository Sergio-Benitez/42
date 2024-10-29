/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:48:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:48:34 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	int	j;

	i = 0;
	map->update_flags = malloc(map->height * sizeof(bool *));
	while (i < map->height)
	{
		map->update_flags[i] = malloc(map->width * sizeof(bool));
		j = 0;
		while (j < map->width)
		{
			map->update_flags[i][j] = true;
			j++;
		}
		i++;
	}
}

mlx_image_t	*weight_wall(t_game *game)
{
	int	total_weight;
	int	i;
	int	random_value;
	int	cumulative_weight;

	total_weight = 0;
	i = 0;
	while (i < NUM_WALL_TEXTURES)
	{
		total_weight += game->wall_weights[i];
		i++;
	}
	random_value = rand() % total_weight;
	cumulative_weight = 0;
	i = 0;
	while (i < NUM_WALL_TEXTURES)
	{
		cumulative_weight += game->wall_weights[i];
		if (random_value < cumulative_weight)
			return (game->img_wall[i]);
		i++;
	}
	return (game->img_wall[0]);
}

int	check_map(t_map *map)
{
	if (!(check_type(map->filename)))
		return (write(2, "Error\nInvalid file extension.\n", 30), 0);
	if (!(check_chars(map)))
	{
		if (map->player_n == 0)
			write(2, "Error\nNo 'Player' found.\n", 25);
		if (map->player_n > 1)
			write(2, "Error\nToo many 'Players' found.\n", 32);
		if (map->exit_n == 0)
			write(2, "Error\nNo 'Exit' found.\n", 23);
		if (map->exit_n > 1)
			write(2, "Error\nToo many 'Exits' found.\n", 30);
		if (map->collect_n == 0)
			write(2, "Error\nNo 'Collectables' found.\n", 31);
		return (0);
	}
	if (!(check_rect(map->data)))
		return (write(2, "Error\nMap must be rectangular.\n", 31), 0);
	if (!(check_frame(map)))
		return (write(2, "Error\nFrame is not correctly closed.\n", 37), 0);
	if (!(check_path(map)))
		return (write(2, "Error\nInvalid path.\n", 20), 0);
	return (1);
}
