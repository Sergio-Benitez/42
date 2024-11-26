/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2024/11/26 19:26:22 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

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
		game->wmoves = NULL;
		game->img_enemy = NULL;
		game->move_count = 0;
		game->frame_count = 0;
	}
}

void	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx = mlx_init(map->width_px, map->height_px, "So_Long_Bonus", true);
	if (!game->mlx)
	{
		cleanup(game);
		return ;
	}
	game->move_count = 0;
	game->frame_count = 0;
	charge_element_textures(game);
	charge_individuals_textures(game);
}

void	ft_moves(t_game *game)
{
	char	*mov;

	if (game->wmoves)
		mlx_delete_image(game->mlx, game->wmoves);
	mov = ft_itoa(game->move_count);
	mov = ft_strjoin("Movements: ", mov);
	game->wmoves = mlx_put_string(game->mlx, mov, 16, 16);
	free (mov);
}

void	game_over(t_game *game)
{
	game->frame_count = -20;
	ft_printf("\n\n\n\n          GAME OVER\n");
	ft_printf("You were caught by the enemy!\n\n\n\n\n\n");
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
