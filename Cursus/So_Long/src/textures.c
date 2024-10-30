/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:32:11 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/31 00:28:18 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	charge_textures(t_game *game)
{
	game->img_bg = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/floor2.png"));
	game->img_wall[0] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/wall2.png"));
	game->wall_weights[0] = 50;
	game->img_wall[1] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/wall3.png"));
	game->wall_weights[1] = 10;
	game->img_wall[3] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/wall5.png"));
	game->wall_weights[3] = 20;
	game->img_player = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/player2.png"));
	game->img_collect = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/soul2.png"));
	game->img_exit_open = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/exit_open.png"));
	game->img_exit_closed = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/exit_closed.png"));
	return (EXIT_SUCCESS);
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
