/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/09/19 11:59:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_game(t_game *game, char *filename)
{
	ft_init_game(game);
	if (ft_parse_file(filename, game) == -1)
		ft_error_exit("Error parsing file");
	if (ft_validate_map(game) == -1)
		ft_error_exit("Invalid map");
	ft_init_player(game);
}

static void	setup_mlx(t_game *game, char *filename)
{
	game->mlx = mlx_init(game->win_width, game->win_height, "Cub3D", true);
	if (!game->mlx)
		ft_error_exit("Failed to initialize MLX42");
	if (ft_load_textures(filename, game) == -1)
		ft_error_exit("Failed to load textures");
	game->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	if (!game->img)
		ft_error_exit("Failed to create image");
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
		ft_error_exit("Failed to put image to window");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_exit("Usage: ./cub3D <map.cub>");
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		ft_error_exit("Map file must have .cub extension");
	setup_game(&game, argv[1]);
	setup_mlx(&game, argv[1]);
	mlx_key_hook(game.mlx, ft_key_press, &game);
	mlx_close_hook(game.mlx, ft_close_window, &game);
	mlx_loop_hook(game.mlx, ft_render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
