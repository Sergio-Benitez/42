/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:53:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/28 21:32:57 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	charge_textures(t_game *game)
{
	game->img_bg = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/floor2.png"));
	game->img_wall[0] = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/wall2.png"));
	game->wall_weights[0] = 50;
	game->img_wall[1] = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/wall3.png"));
	game->wall_weights[1] = 10;
	game->img_wall[3] = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/wall5.png"));
	game->wall_weights[3] = 20;
	game->img_player = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/player2.png"));
	game->img_collect = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/soul2.png"));
	game->img_exit_open = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/exit_open.png"));
	game->img_exit_closed = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/exit_closed.png"));
	return (EXIT_SUCCESS);
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
		new_pos.y -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		new_pos.y += 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		new_pos.x -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		new_pos.x += 1;
	handle_movement(game, old_pos, new_pos);
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
					mark_exit_for_update(game);
			}
			game->map->player_pos = new_pos;
			game->move_count++;
			printf("Movimientos: %d\n", game->move_count);
			if (game->map->data[new_pos.y][new_pos.x] == 'E'
				&& game->map->collect_n == 0)
				game->frame_count = -20;
			game->map->update_flags[old_pos.y][old_pos.x] = true;
			game->map->update_flags[new_pos.y][new_pos.x] = true;
		}
	}
}

void	mark_exit_for_update(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->data[i][j] == 'E')
				game->map->update_flags[i][j] = true;
			j++;
		}
		i++;
	}
}
