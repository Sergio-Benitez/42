/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:53:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/25 23:13:08 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(void *param)
{
	t_game *game = (t_game *)param;
	handle_input(game);
	render_map(game);
}

void handle_input(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->map->player_y -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->map->player_y += 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->map->player_x -= 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->map->player_x += 1;
}

int	charge_textures(t_game *game)
{
	game->img_bg = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/floor.png"));
	game->img_wall = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/wall.png"));
	game->img_player = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/player.png"));
	game->img_collect = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/soul.png"));
	if (!game->img_collect)
    {
        printf("Error cargando la textura del coleccionable: %s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }
	game->img_exit = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/exit.png"));
	return (EXIT_SUCCESS);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	mlx_image_to_window(game->mlx, game->img_wall, 0, 0);
	i = 0;
	while (game->map->data[i])
	{
		j = 0;
		while (game->map->data[i][j])
		{
			mlx_image_to_window(game->mlx, game->img_bg, j * TILE_SIZE, i * TILE_SIZE);
			if (game->map->data[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img_wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map->data[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img_collect, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map->data[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->img_exit, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->img_player, game->map->player_x * TILE_SIZE, game->map->player_y * TILE_SIZE);

}
