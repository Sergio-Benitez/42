/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:53:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/25 21:40:59 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	charge_textures(t_game *game)
{
	game->img_bg = mlx_texture_to_image(game->mlx, mlx_load_png("Graphics/floor2.png"));
    if (!game->img_bg)
    {
        printf("Error cargando la textura del suelo: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(game->mlx);
        return (EXIT_FAILURE);
    }

    game->img_wall = mlx_texture_to_image(game->mlx, mlx_load_png("Graphics/wall.png"));
    if (!game->img_wall)
    {
        printf("Error cargando la textura de la pared: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(game->mlx);
        return (EXIT_FAILURE);
    }
	
	game->img_player = mlx_texture_to_image(game->mlx, mlx_load_png("Graphics/player.png"));
	if (!game->img_player)
    {
        printf("Error cargando la textura del jugador: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(game->mlx);
        return (EXIT_FAILURE);
    }

	game->img_collect = mlx_texture_to_image(game->mlx, mlx_load_png("Graphics/soul.png"));
	if (!game->img_collect)
    {
        printf("Error cargando la textura del coleccionable: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(game->mlx);
        return (EXIT_FAILURE);
    }
	
	game->img_exit = mlx_texture_to_image(game->mlx, mlx_load_png("Graphics/exit.png"));
	if (!game->img_exit)
    {
        printf("Error cargando la textura de la salida: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(game->mlx);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void	render_map(t_game *game)
{
	if (game->map[0][0] == '1')
		mlx_image_to_window(game->mlx, game->img_wall, 0, 0);
	
    // Dibujar el fondo en toda la ventana primero
    int i = 0;
    while (game->map[i])
    {
        int j = 0;
        while (game->map[i][j])
        {
            if (mlx_image_to_window(game->mlx, game->img_bg, j * TILE_SIZE, i * TILE_SIZE) == -1)
            {
                printf("Error al dibujar el fondo en (%d, %d): %s\n", j, i, mlx_strerror(mlx_errno));
            }
            j++;
        }
        i++;
    }

    // Dibujar las weas después
    i = 0;
    while (game->map[i])
    {
        int j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == '1')  // Si es una pared
            {
                if (mlx_image_to_window(game->mlx, game->img_wall, j * TILE_SIZE, i * TILE_SIZE) == -1)
                {
                    printf("Error al dibujar la pared en (%d, %d): %s\n", j, i, mlx_strerror(mlx_errno));
                }
            }
			else if (game->map[i][j] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->img_player, j * TILE_SIZE, i * TILE_SIZE) == -1)
                {
                    printf("Error al dibujar el jugador en (%d, %d): %s\n", j, i, mlx_strerror(mlx_errno));
                }
			}
			else if (game->map[i][j] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->img_collect, j * TILE_SIZE, i * TILE_SIZE) == -1)
                {
                    printf("Error al dibujar el coleccionable en (%d, %d): %s\n", j, i, mlx_strerror(mlx_errno));
                }
			}
			else if (game->map[i][j] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->img_exit, j * TILE_SIZE, i * TILE_SIZE) == -1)
                {
                    printf("Error al dibujar la salida en (%d, %d): %s\n", j, i, mlx_strerror(mlx_errno));
                }
			}
            j++;
        }
        i++;
    }
}