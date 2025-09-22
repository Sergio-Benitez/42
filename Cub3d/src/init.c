/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/09/19 11:59:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->sprites = NULL;
	game->sprite_count = 0;
	game->tex.north = NULL;
	game->tex.south = NULL;
	game->tex.east = NULL;
	game->tex.west = NULL;
	game->tex.floor_color = 0;
	game->tex.ceiling_color = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
}
