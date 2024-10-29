/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:24:25 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:51:46 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_map(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->update_flags[i][j])
			{
				render_tile(game, i, j);
				game->map->update_flags[i][j] = false;
			}
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->img_player, game->map->player_pos.x
		* TILE_SIZE, game->map->player_pos.y * TILE_SIZE);
}

void	render_tile(t_game *game, int i, int j)
{
	mlx_image_t	*wall_texture;

	mlx_image_to_window(game->mlx, game->img_bg, j * TILE_SIZE, i * TILE_SIZE);
	if (game->map->data[i][j] == '1')
	{
		wall_texture = weight_wall(game);
		mlx_image_to_window(game->mlx, wall_texture,
			j * TILE_SIZE, i * TILE_SIZE);
	}
	else if (game->map->data[i][j] == 'C')
		mlx_image_to_window(game->mlx, game->img_collect,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map->data[i][j] == 'E')
	{
		if (game->map->collect_n == 0)
			mlx_image_to_window(game->mlx, game->img_exit_open,
				j * TILE_SIZE, i * TILE_SIZE);
		else
			mlx_image_to_window(game->mlx, game->img_exit_closed,
				j * TILE_SIZE, i * TILE_SIZE);
	}
}
