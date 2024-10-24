/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:35:03 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/24 18:45:11 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

mlx_image_t *background;  // Variable global para el fondo

void render_background(void* param)
{
    mlx_t* mlx = (mlx_t*) param;

    int texture_width = background->width;
    int texture_height = background->height;

    int x = 0;
    while (x < WIDTH)
    {
        int y = 0;
        while (y < HEIGHT)
        {
            mlx_image_to_window(mlx, background, x, y);
            y += texture_height;  // Avanzar en la dirección vertical
        }
        x += texture_width;  // Avanzar en la dirección horizontal
    }
}

int main(void)
{
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
    if (!mlx)
    {
        printf("Error al iniciar MLX42: %s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }

    // Cargar la textura de fondo
    background = mlx_texture_to_image(mlx, mlx_load_png("Graphics/floor2.png"));
    if (!background)
    {
        printf("Error cargando la textura: %s\n", mlx_strerror(mlx_errno));
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }

    // Configurar el hook para renderizar el fondo
    mlx_loop_hook(mlx, render_background, mlx);

    // Bucle principal
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MLX42/include/MLX42/MLX42.h"

#define TILE_SIZE 64  // Tamaño de cada tile

mlx_image_t* background;
mlx_image_t* wall;

char* map[] = {
    "1111111111111111111111111111111111",
	"1E0000000000000C00000C000000000001",
	"1010010100100000101001000000010101",
	"1010010100100000101001000000010101",
	"1010010100100000101001000000010101",
	"1010010010101010001001000000010101",
	"1P0000000C00C0000000000000000000C1",
	"1010010100100000101001000000010101",
	"1E0000000000000C00000C000000000001",
	"1111111111111111111111111111111111",
    NULL
};

// Función para calcular el tamaño del mapa
int get_map_width(char** map)
{
    return strlen(map[0]) * TILE_SIZE;  // El ancho de la primera fila define el ancho total
}

int get_map_height(char** map)
{
    int height = 0;
    while (map[height])
        height++;
    return height * TILE_SIZE;  // Número de filas * tamaño de cada tile
}

void render_map(void* param)
{
    mlx_t* mlx = (mlx_t*) param;
	if (map[0][0] == '1')
		mlx_image_to_window(mlx, wall, 0, 0);

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
}

int main(void)
{
    // Calcular el tamaño de la ventana en función del mapa
    int width = get_map_width(map);
    int height = get_map_height(map);

    mlx_t* mlx = mlx_init(width, height, "so_long", true);
    if (!mlx)
    {
        printf("Error al iniciar MLX42: %s\n", mlx_strerror(mlx_errno));
        return (EXIT_FAILURE);
    }

    // Cargar las texturas de suelo y paredes
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

    // Configurar el hook para renderizar el mapa
    mlx_loop_hook(mlx, render_map, mlx);

    // Bucle principal
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}