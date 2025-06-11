/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2025/06/09 13:00:37 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_game(t_game *game, t_map *map)
{
	game->img_bg = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->map = map;
	game->mlx = mlx_init(map->width_px, map->height_px, "So_Long", true);
	if (!game->mlx)
	{
		cleanup(game);
		return ;
	}
	game->move_count = 0;
	game->frame_count = 0;
	charge_textures(game);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
	{
		if (argc == 1)
			return (write(2, "Error:\n  -Enter a map to run.\n", 30), 1);
		else
			return (write(2, "Error:\n  -Too many arguments.\n", 30), 1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (EXIT_FAILURE);
	if (!load_create_map(argv[1]), map)
		return (free(map), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (cleanup(game), EXIT_FAILURE);
	init_game_struct(game);
	init_game(game, map);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (EXIT_SUCCESS);
}
