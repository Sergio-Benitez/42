/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:32:11 by sbenitez          #+#    #+#             */
/*   Updated: 2024/11/25 21:55:50 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	charge_textures(t_game *game)
{
	game->img_bg = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/floor2.png"));
	game->img_wall = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/wall2.png"));
	game->img_player = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/player_right.png"));
	game->img_collect = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/soul2.png"));
	game->img_exit = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/exit_open.png"));
	return (EXIT_SUCCESS);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;

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
	mlx_image_to_window(game->mlx, game->img_bg, j * TILE_SIZE, i * TILE_SIZE);
	if (game->map->data[i][j] == '1')
		mlx_image_to_window(game->mlx, game->img_wall,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map->data[i][j] == 'C')
		mlx_image_to_window(game->mlx, game->img_collect,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map->data[i][j] == 'E')
	{
		mlx_image_to_window(game->mlx, game->img_exit,
			j * TILE_SIZE, i * TILE_SIZE);
	}
}
