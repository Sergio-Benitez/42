/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/25 13:42:12 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	t_params	params;

	if (argc != 2)
	{
		if (argc == 1)
			return (write(2, "Error\nEnter a map to run.\n", 26), 1);
		else
			return (write(2, "Error\nToo many arguments.\n", 26), 1);
	}
	i = 0;
	map = load_create_map(argv[1]);
	if (!map)
		return (1);
	params.mlx = mlx_init(map->width_px, map->height_px, "so_long", true);
	if (!params.mlx)
		return (write(2, "Error starting MLX42\n",21), EXIT_FAILURE);
	charge_textures(params.mlx);
	params.map_data = map->data;
	mlx_loop_hook(params.mlx, (void (*)(void *))render_map, &params);
//	render_map(mlx, map->data);
	mlx_loop(params.mlx);
	mlx_terminate(params.mlx);
	return (ft_free_exit(map->data, map), EXIT_SUCCESS);
}
