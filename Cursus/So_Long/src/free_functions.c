/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:40:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/31 01:08:32 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_matrix(void **matrix, int height)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (i < height)
		{
			if (matrix[i])
				free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

void	ft_free_exit(char **map_data, t_map *map)
{
	int	i;

	i = 0;
	if (map_data)
	{
		while (i < map->height)
		{
			free(map_data[i]);
			i++;
		}
		free(map_data);
	}
	if (map)
		free(map);
	exit (1);
}

void	free_textures(t_game *game)
{
	int	i;

	if (game->img_bg)
		mlx_delete_image(game->mlx, game->img_bg);
	if (game->img_player)
		mlx_delete_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_delete_image(game->mlx, game->img_collect);
	if (game->img_exit_open)
		mlx_delete_image(game->mlx, game->img_exit_open);
	if (game->img_exit_closed)
		mlx_delete_image(game->mlx, game->img_exit_closed);
	i = 0;
	while (i < NUM_WALL_TEXTURES)
	{
		if (game->img_wall[i])
			mlx_delete_image(game->mlx, game->img_wall[i]);
		i++;
	}
}

void	cleanup(t_game *game)
{
	int	i;

	i = 0;
	if (game)
	{
		if (game->map)
		{
			if (game->map->data)
			{
				while (i < game->map->height)
				{
					free(game->map->data[i]);
					i++;
				}
				free(game->map->data);
			}
			free(game->map);
		}
		free_textures(game);
		free_matrix((void **)game->map->update_flags, game->map->height);
		mlx_terminate(game->mlx);
		free(game);
	}
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
