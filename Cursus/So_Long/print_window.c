/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:53:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/27 19:53:27 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(void *param)
{
    static struct timeval last_time;
    struct timeval current_time;
    double elapsed_time;
    t_game *game = (t_game *)param;

    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec - last_time.tv_sec) + 
                   (current_time.tv_usec - last_time.tv_usec) / 1000000.0;

    if (elapsed_time < 1.0 / 8.0) // Limita la frecuencia de actualización a 24 FPS
        return;

    last_time = current_time;

    handle_input(game);
    render_map(game);
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

void handle_input(t_game *game)
{
    int old_x = game->map->player_x;
    int old_y = game->map->player_y;
    int new_x = old_x;
    int new_y = old_y;

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
        new_y -= 1;
    if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
        new_y += 1;
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
        new_x -= 1;
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
        new_x += 1;

    // Verifica colisiones con paredes
    if (game->map->data[new_y][new_x] != '1')
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
                    for (int i = 0; i < game->map->height; i++)
                    {
                        for (int j = 0; j < game->map->width; j++)
                        {
                            if (game->map->data[i][j] == 'E')
                            {
                                game->map->update_flags[i][j] = true;
                            }
                        }
                    }
                }
            }

            game->map->player_x = new_x;
            game->map->player_y = new_y;

            // Verifica si el jugador pisa la salida
            if (game->map->data[new_y][new_x] == 'E' && game->map->collect_n == 0)
            {
                mlx_close_window(game->mlx);
            }

            // Marca las posiciones antiguas y nuevas del jugador para actualización
            game->map->update_flags[old_y][old_x] = true;
            game->map->update_flags[new_y][new_x] = true;
        }
    }
}
/*void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
//	mlx_image_to_window(game->mlx, game->img_wall, 0, 0);
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
*/
void render_map(t_game *game)
{
    int i = 0;
    int j;

    while (i < game->map->height)
    {
        j = 0;
        while (j < game->map->width)
        {
            if (game->map->update_flags[i][j])
            {
                mlx_image_to_window(game->mlx, game->img_bg, j * TILE_SIZE, i * TILE_SIZE);
                if (game->map->data[i][j] == '1')
                    mlx_image_to_window(game->mlx, game->img_wall, j * TILE_SIZE, i * TILE_SIZE);
                else if (game->map->data[i][j] == 'C')
                    mlx_image_to_window(game->mlx, game->img_collect, j * TILE_SIZE, i * TILE_SIZE);
                else if (game->map->data[i][j] == 'E' && game->map->collect_n == 0)
                    mlx_image_to_window(game->mlx, game->img_exit, j * TILE_SIZE, i * TILE_SIZE);

                // Resetea la bandera después de renderizar
                game->map->update_flags[i][j] = false;
            }
            j++;
        }
        i++;
    }

    // Renderiza la posición del jugador
    mlx_image_to_window(game->mlx, game->img_player, game->map->player_x * TILE_SIZE, game->map->player_y * TILE_SIZE);
}