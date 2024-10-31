/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:44:07 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/31 03:58:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void clear_message_area(t_game *game, int x, int y, int width, int height)
{
    mlx_image_t *clear_img = mlx_new_image(game->mlx, width, height);
    mlx_image_to_color(clear_img, 0xCC000000); // Color negro con 80% de opacidad
    mlx_image_to_window(game->mlx, clear_img, x, y);
    mlx_delete_image(game->mlx, clear_img);
}
void display_move_count(t_game *game)
{
    static char *prev_display_str = NULL;
    char *move_count_str;
    char *display_str;

    // Posición del contador
    int x = 10;
    int y = 10;

    // Limpiar el área del mensaje
    clear_message_area(game, x - 10, y - 10, 160, 20);

    // Colocar la imagen de fondo para limpiar el texto anterior
    mlx_image_to_window(game->mlx, game->counter_bg, x, y);

    // Convertir el contador de movimientos a cadena
    move_count_str = ft_itoa(game->move_count);

    // Crear la cadena completa a mostrar
    display_str = ft_strjoin("Movimientos: ", move_count_str);

    // Mostrar el contador de movimientos en pantalla
    mlx_put_string(game->mlx, display_str, x, y);

    // Liberar memoria de la cadena anterior
    if (prev_display_str)
        free(prev_display_str);

    // Guardar la cadena actual para liberarla en la próxima actualización
    prev_display_str = display_str;

    // Liberar memoria de la cadena de movimientos
    free(move_count_str);
}

void mlx_image_to_color(mlx_image_t *img, uint32_t color)
{
    int total_pixels = img->width * img->height;
    int i = 0;

    while (i < total_pixels)
    {
        img->pixels[i * 4 + 0] = (color >> 16) & 0xFF; // Canal R
        img->pixels[i * 4 + 1] = (color >> 8) & 0xFF;  // Canal G
        img->pixels[i * 4 + 2] = color & 0xFF;         // Canal B
        img->pixels[i * 4 + 3] = (color >> 24) & 0xFF; // Canal A
        i++;
    }
}
