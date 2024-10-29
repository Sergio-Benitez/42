/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:48:22 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init(map->width_px, map->height_px, "so_long", true);
	if (!game->mlx)
	{
		write(2, "Error starting MLX42.\n", 21);
		exit(EXIT_FAILURE);
	}
	game->move_count = 0;
	game->frame_count = 0;
	charge_textures(game);
	game->map = map;
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
	{
		if (argc == 1)
			return (write(2, "Error\nEnter a map to run.\n", 26), 1);
		else
			return (write(2, "Error\nToo many arguments.\n", 26), 1);
	}
	map = load_create_map(argv[1]);
	if (!map)
		return (1);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (write(2, "Error\nMemory allocation fail.\n", 30), EXIT_FAILURE);
	init_game(game, map);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (ft_free_exit(map->data, map), EXIT_SUCCESS);
}
