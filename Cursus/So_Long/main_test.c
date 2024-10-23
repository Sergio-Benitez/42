/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:35:03 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/23 20:54:18 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

mlx_image_t* background;  // Variable global para el fondo

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
    background = mlx_texture_to_image(mlx, mlx_load_png("Graphics/floor.png"));
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
