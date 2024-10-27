/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:53:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/27 23:36:16 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(void *param)
{
    t_game *game = (t_game *)param;

	if (game->frame_count < 0)
    {
        game->frame_count++;
        if (game->frame_count == 0)
        {
            mlx_close_window(game->mlx);
        }
        return;
    }
    if (game->frame_count++ < 5) // Ajusta la frecuencia de actualización (5 frames por actualización)
        return;
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
	game->img_wall[1] = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/wall3.png"));
//	game->img_wall[2] = mlx_texture_to_image(
//			game->mlx, mlx_load_png("Graphics/wall4.png"));
	game->img_wall[3] = mlx_texture_to_image(
			game->mlx, mlx_load_png("Graphics/wall5.png"));
//	game->img_wall[4] = mlx_texture_to_image(
//			game->mlx, mlx_load_png("Graphics/wall6.png"));
	game->wall_weights[0] = 50;
	game->wall_weights[1] = 10;
//	game->wall_weights[2] = 40;
	game->wall_weights[3] = 20;
//	game->wall_weights[4] = 10;
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

void handle_input(t_game *game)
{
    int old_x = game->map->player_x;
    int old_y = game->map->player_y;
    int new_x = old_x;
    int new_y = old_y;

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        new_y -= 1;
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        new_y += 1;
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        new_x -= 1;
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        new_x += 1;

    // Verifica colisiones con paredes y puerta cerrada
    if (game->map->data[new_y][new_x] != '1' && !(game->map->data[new_y][new_x] == 'E' && game->map->collect_n > 0))
    {
        if (new_x != old_x || new_y != old_y)
        {
            // Verifica si el jugador recoge un coleccionable
            if (game->map->data[new_y][new_x] == 'C')
            {
                game->map->data[new_y][new_x] = '0'; // Elimina el coleccionable del mapa
                game->map->collect_n--; // Decrementa el contador de coleccionables

                // Marca la casilla de salida para actualización si se han recogido todos los coleccionables
                if (game->map->collect_n == 0)
                {
                    int i = 0;
                    while (i < game->map->height)
                    {
                        int j = 0;
                        while (j < game->map->width)
                        {
                            if (game->map->data[i][j] == 'E')
                            {
                                game->map->update_flags[i][j] = true;
                            }
                            j++;
                        }
                        i++;
                    }
                }
            }

            game->map->player_x = new_x;
            game->map->player_y = new_y;

            // Incrementa el contador de movimientos y muestra el número de movimientos en la terminal
            game->move_count++;
            printf("Movimientos: %d\n", game->move_count);

            // Verifica si el jugador pisa la salida
            if (game->map->data[new_y][new_x] == 'E' && game->map->collect_n == 0)
            {
                game->frame_count = -20;
            }

            // Marca las posiciones antiguas y nuevas del jugador para actualización
            game->map->update_flags[old_y][old_x] = true;
            game->map->update_flags[new_y][new_x] = true;
        }
    }
}

void render_map(t_game *game)
{
	int			i;
	int			j;
	mlx_image_t	*wall_texture;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->update_flags[i][j])
			{
				mlx_image_to_window(game->mlx, game->img_bg, j * TILE_SIZE, i * TILE_SIZE);
				if (game->map->data[i][j] == '1')
				{
					wall_texture = get_weighted_random_wall_texture(game);
					mlx_image_to_window(game->mlx, wall_texture, j * TILE_SIZE, i * TILE_SIZE);
				}
				else if (game->map->data[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img_collect, j * TILE_SIZE, i * TILE_SIZE);
				else if (game->map->data[i][j] == 'E')
				{
					if (game->map->collect_n == 0)
						mlx_image_to_window(game->mlx, game->img_exit_open, j * TILE_SIZE, i * TILE_SIZE);
					else
						mlx_image_to_window(game->mlx, game->img_exit_closed, j * TILE_SIZE, i * TILE_SIZE);
				}
				game->map->update_flags[i][j] = false;
			}
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->img_player, game->map->player_x * TILE_SIZE, game->map->player_y * TILE_SIZE);
}