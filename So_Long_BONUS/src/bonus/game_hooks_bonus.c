/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:53:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/11/25 23:15:25 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->frame_count < 0)
	{
		game->frame_count++;
		if (game->frame_count == 0)
			mlx_close_window(game->mlx);
		return ;
	}
	if (game->frame_count++ < 5)
		return ;
	game->frame_count = 0;
	handle_input(game);
	render_map(game);
}

void	handle_input(t_game *game)
{
	t_coords	old_pos;
	t_coords	new_pos;

	old_pos = game->map->player_pos;
	new_pos = old_pos;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, &new_pos, 0, -1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, &new_pos, 0, 1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, &new_pos, -1, 0);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, &new_pos, 1, 0);
	handle_movement(game, old_pos, new_pos);
}

void	move_player(t_game *game, t_coords *pos, int dx, int dy)
{
	pos->x += dx;
	pos->y += dy;
	if (dy == -1)
		game->img_player = game->img_player_up;
	else if (dy == 1)
		game->img_player = game->img_player_down;
	else if (dx == -1)
		game->img_player = game->img_player_left;
	else if (dx == 1)
		game->img_player = game->img_player_right;
}

void	handle_movement(t_game *game, t_coords old_pos, t_coords new_pos)
{
	if (game->map->data[new_pos.y][new_pos.x] != '1' && !(
			game->map->data[new_pos.y][new_pos.x] == 'E'
			&& game->map->collect_n > 0))
	{
		if (new_pos.x != old_pos.x || new_pos.y != old_pos.y)
		{
			if (game->map->data[new_pos.y][new_pos.x] == 'C')
			{
				game->map->data[new_pos.y][new_pos.x] = '0';
				game->map->collect_n--;
				if (game->map->collect_n == 0)
					game->map->update_flags[game->map->exit_pos.y]
					[game->map->exit_pos.x] = true;
			}
			game->map->player_pos = new_pos;
			game->move_count++;
			ft_moves(game);
			if (game->map->data[new_pos.y][new_pos.x] == 'E'
				&& game->map->collect_n == 0)
				game->frame_count = -20;
			game->map->update_flags[old_pos.y][old_pos.x] = true;
			game->map->update_flags[new_pos.y][new_pos.x] = true;
			if (game->map->data[new_pos.y][new_pos.x] == 'R')
			{
				mlx_close_window(game->mlx);
				ft_printf("GAME OVER\nYou were caught by the enemy!\n");
			}
		}
	}
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
