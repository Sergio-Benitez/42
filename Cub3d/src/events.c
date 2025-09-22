/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/21 17:46:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == ESC_KEY)
		ft_close_window(game);
	else if (keydata.key == W_KEY)
		ft_move_player(game, game->player.dir_x * MOVE_SPEED,
			game->player.dir_y * MOVE_SPEED);
	else if (keydata.key == S_KEY)
		ft_move_player(game, -game->player.dir_x * MOVE_SPEED,
			-game->player.dir_y * MOVE_SPEED);
	else if (keydata.key == A_KEY)
		ft_move_player(game, game->player.dir_y * MOVE_SPEED,
			-game->player.dir_x * MOVE_SPEED);
	else if (keydata.key == D_KEY)
		ft_move_player(game, -game->player.dir_y * MOVE_SPEED,
			game->player.dir_x * MOVE_SPEED);
	else if (keydata.key == LEFT_ARROW)
		ft_rotate_player(game, -ROT_SPEED);
	else if (keydata.key == RIGHT_ARROW)
		ft_rotate_player(game, ROT_SPEED);
}

void	ft_close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_cleanup_game(game);
	exit(0);
}

void	ft_move_player(t_game *game, double move_x, double move_y)
{
	int	new_x;
	int	new_y;

	new_x = (int)(game->player.x + move_x);
	new_y = (int)(game->player.y + move_y);
	if (new_x >= 0 && new_x < game->map_width
		&& new_y >= 0 && new_y < game->map_height
		&& new_x < (int)ft_strlen(game->map[new_y])
		&& game->map[new_y][new_x] != '1')
	{
		if (game->map[(int)game->player.y][new_x] != '1')
			game->player.x += move_x;
		if (game->map[new_y][(int)game->player.x] != '1')
			game->player.y += move_y;
	}
}

void	ft_rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}
