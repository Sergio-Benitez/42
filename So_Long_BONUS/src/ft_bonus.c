/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:44:07 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/31 14:09:33 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void display_move_count(t_game *game)
{
    static char *prev_display_str = NULL;
    char *move_count_str;
    char *display_str;

    // Posición del contador
    int x = 10;
    int y = 10;

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

void init_collectibles(t_game *game)
{
    // Inicializa las posiciones de los coleccionables
    game->map->collect_pos = malloc(sizeof(t_coords) * game->map->collect_n);
    if (!game->map->collect_pos)
    {
        // Manejar error de asignación de memoria
        fprintf(stderr, "Error asignando memoria para collect_pos\n");
        exit(EXIT_FAILURE);
    }

    // Llama a find_pos para inicializar las posiciones de los coleccionables
    find_pos(game->map);
}

void init_collectible_animation(t_game *game)
{
	game->collect_frame[0] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/soul2.png"));
	game->collect_frame[1] = mlx_texture_to_image(
			game->mlx, mlx_load_png("textures/soul3.png"));
    game->current_frame = 0;
}

void render_collectibles(t_game *game)
{
    int i = 0;
    while (i < game->map->collect_n)
    {
        int x = game->map->collect_pos[i].x;
        int y = game->map->collect_pos[i].y;
        mlx_image_to_window(game->mlx, game->collect_frame[game->current_frame], x * TILE_SIZE, y * TILE_SIZE);
        i++;
    }
}

void update_collectible_flags(t_game *game)
{
    int i = 0;
    while (i < game->map->collect_n)
    {
        int x = game->map->collect_pos[i].x;
        int y = game->map->collect_pos[i].y;
        game->map->update_flags[y][x] = true; // Marcar las posiciones de los coleccionables como true
        i++;
    }
}

void update_collectible_animation(t_game *game)
{
    game->anim_counter++;
    if (game->anim_counter >= game->anim_speed)
    {
        game->current_frame = (game->current_frame + 1) % NUM_COLLECT_TEXTURES;
        game->anim_counter = 0;
    }
}

void handle_collectible(t_game *game, int x, int y)
{
    int i = 0;
    while (i < game->map->collect_n)
    {
        if (game->map->collect_pos[i].x == x && game->map->collect_pos[i].y == y)
        {
            int j = i;
            while (j < game->map->collect_n - 1)
            {
                game->map->collect_pos[j] = game->map->collect_pos[j + 1];
                j++;
            }
            game->map->collect_n--;
            game->map->update_flags[y][x] = true; // Marcar la posición como actualizada

            // Abrir la salida si todos los coleccionables han sido recogidos
            if (game->map->collect_n == 0)
            {
                game->map->update_flags[game->map->exit_pos.y][game->map->exit_pos.x] = true;
            }
            break;
        }
        i++;
    }
}