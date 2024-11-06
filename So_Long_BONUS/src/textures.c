/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:32:11 by sbenitez          #+#    #+#             */
/*   Updated: 2024/11/06 19:37:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	charge_textures(t_game *game)
{
	game->img_bg = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/floor2.png"));
	game->img_wall[0] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/wall2.png"));
	game->img_wall[1] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/wall3.png"));
	game->img_wall[2] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/wall5.png"));
	game->img_player_up = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/player_up.png"));
	game->img_player_down = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/player_down.png"));
	game->img_player_left = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/player_left.png"));
	game->img_player_right = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/player_right.png"));
	game->img_collect = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/soul2.png"));
	game->img_exit_open = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/exit_open.png"));
	game->img_exit_closed = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/exit_closed.png"));
	return (EXIT_SUCCESS);
}

mlx_image_t	*select_wall_texture(int x, int y, t_game *game)
{
	int	sum;

	sum = ((x * 31) + (y * 17) + (x ^ y)) % 100;
	if (sum < 80)
		return (game->img_wall[0]);
	else if (sum < 90)
		return (game->img_wall[2]);
	else
		return (game->img_wall[1]);
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
	mlx_image_t	*wall_texture;

	mlx_image_to_window(game->mlx, game->img_bg, j * TILE_SIZE, i * TILE_SIZE);
	if (game->map->data[i][j] == '1')
	{
		wall_texture = select_wall_texture(i, j, game);
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
