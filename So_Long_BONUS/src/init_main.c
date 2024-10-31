/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/31 13:57:23 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game_struct(t_game *game)
{
	int	i;

	i = 0;
	if (game)
	{
		game->mlx = NULL;
		game->map = NULL;
		game->img_bg = NULL;
		while (i < NUM_WALL_TEXTURES)
		{
			game->img_wall[i] = NULL;
			i++;
		}
		game->img_player = NULL;
		game->img_collect = NULL;
		game->img_exit_open = NULL;
		game->img_exit_closed = NULL;
		game->move_count = 0;
		game->frame_count = 0;
	}
}

void	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx = mlx_init(map->width_px, map->height_px, "So_Long", true);
	if (!game->mlx)
	{
		cleanup(game);
		return ;
	}
	game->move_count = 0;
	game->frame_count = 0;
    game->counter_bg = mlx_new_image(game->mlx, 160, 20); // Ancho y alto del área del contador
    mlx_image_to_color(game->counter_bg, 0x80000000);
	game->anim_speed = 5;
	game->anim_counter = 0;
	game->anim_direction = 1;
	init_collectibles(game);
	init_collectible_animation(game);
	charge_textures(game);
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
	map = malloc(sizeof(t_map));
	if (!map)
		return (EXIT_FAILURE);
	map = load_create_map(argv[1]);
	if (!map)
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
