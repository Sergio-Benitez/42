/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/09/19 11:59:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	ft_init_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width && game->map[y])
		{
			if (is_player_char(game->map[y][x]))
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
				ft_set_player_direction(game, game->map[y][x]);
				game->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
