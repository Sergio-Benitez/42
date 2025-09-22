/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/03 17:54:24 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cleanup_game(t_game *game)
{
	ft_cleanup_textures(game);
	ft_cleanup_map(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	ft_cleanup_textures(t_game *game)
{
	if (game->tex.north && game->tex.north != (mlx_texture_t *)1)
		mlx_delete_texture(game->tex.north);
	if (game->tex.south && game->tex.south != (mlx_texture_t *)1)
		mlx_delete_texture(game->tex.south);
	if (game->tex.east && game->tex.east != (mlx_texture_t *)1)
		mlx_delete_texture(game->tex.east);
	if (game->tex.west && game->tex.west != (mlx_texture_t *)1)
		mlx_delete_texture(game->tex.west);
}

void	ft_cleanup_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
