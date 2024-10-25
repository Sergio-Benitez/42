/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:53:16 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/25 13:43:56 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t* background;
mlx_image_t* wall;


int	charge_textures(mlx_t *mlx)
{
	background = mlx_texture_to_image(mlx, mlx_load_png("Graphics/floor2.png"));
    if (!background)
    {
        printf("Error cargando la textura del suelo: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }

    wall = mlx_texture_to_image(mlx, mlx_load_png("Graphics/wall.png"));
    if (!wall)
    {
        printf("Error cargando la textura de la pared: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void	render_map(t_params *params)
{
	mlx_t *mlx = params->mlx;
    char **map = params->map_data;
	if (!wall || !background)
	{
   		printf("Error: texturas no inicializadas\n");
    	return;
	}
    if (!map)
    {
        printf("Error: mapa no inicializado\n");
        return;
    }
	if (map[0][0] == '1')
	{
		mlx_image_to_window(mlx, wall, 0, 0);
		printf("Impresa la esquina\n");
	}
		
	
    // Dibujar el fondo en toda la ventana primero
    int i = 0;
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            if (mlx_image_to_window(mlx, background, j * TILE_SIZE, i * TILE_SIZE) == -1)
            {
                printf("Error al dibujar el fondo en (%d, %d): %s\n", j, i, mlx_strerror(mlx_errno));
            }
            j++;
        }
        i++;
    }

    // Dibujar las paredes después
    i = 0;
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')  // Si es una pared
            {
                if (mlx_image_to_window(mlx, wall, j * TILE_SIZE, i * TILE_SIZE) == -1)
                {
                    printf("Error al dibujar la pared en (%d, %d): %s\n", j, i, mlx_strerror(mlx_errno));
                }
            }
            j++;
        }
        i++;
    }
	printf("Renderizando mapa...\n");
}