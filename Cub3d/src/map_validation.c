/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/02 23:17:21 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_surrounded_by_walls(t_game *game, int x, int y)
{
	if (x == 0 || y == 0 || x >= game->map_width - 1
		|| y >= game->map_height - 1)
		return (0);
	if (x >= (int)ft_strlen(game->map[y]) - 1)
		return (0);
	if (x - 1 < 0 || game->map[y][x - 1] == ' ')
		return (0);
	if (x + 1 >= (int)ft_strlen(game->map[y]) || game->map[y][x + 1] == ' ')
		return (0);
	if (y - 1 < 0 || x >= (int)ft_strlen(game->map[y - 1])
		|| game->map[y - 1][x] == ' ')
		return (0);
	if (y + 1 >= game->map_height || x >= (int)ft_strlen(game->map[y + 1]))
		return (0);
	if (game->map[y + 1][x] == ' ')
		return (0);
	return (1);
}

static int	check_player_count(t_game *game)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
				game->map[y][x] == 'E' || game->map[y][x] == 'W')
				player_count++;
			x++;
		}
		y++;
	}
	return (player_count == 1);
}

static int	check_valid_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (!ft_is_valid_element(game->map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_walls_closed(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'N' ||
				game->map[y][x] == 'S' || game->map[y][x] == 'E' ||
				game->map[y][x] == 'W')
			{
				if (!is_surrounded_by_walls(game, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_validate_map(t_game *game)
{
	if (!game->map || game->map_height == 0)
		return (-1);
	if (!check_valid_characters(game))
		return (-1);
	if (!check_player_count(game))
		return (-1);
	if (!check_walls_closed(game))
		return (-1);
	return (0);
}
