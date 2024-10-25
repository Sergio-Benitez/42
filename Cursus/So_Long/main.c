/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/25 22:54:12 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_game		*game;

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
	game->mlx = mlx_init(map->width_px, map->height_px, "so_long", true);
	if (!game->mlx)
		return (write(2, "Error starting MLX42.\n", 21), EXIT_FAILURE);
	charge_textures(game);
	game->map = map;
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (ft_free_exit(map->data, map), EXIT_SUCCESS);
}
