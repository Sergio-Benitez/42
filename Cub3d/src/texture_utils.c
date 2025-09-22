/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/03 18:05:11 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*ft_get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		return (game->tex.west);
	else if (ray->side == 0 && ray->dir_x < 0)
		return (game->tex.east);
	else if (ray->side == 1 && ray->dir_y > 0)
		return (game->tex.north);
	else
		return (game->tex.south);
}

void	ft_calculate_texture_coords(t_game *game, t_ray *ray,
	mlx_texture_t *texture, int y)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		ray->tex_x = texture->width - ray->tex_x - 1;
	ray->tex_y = (y - game->win_height / 2 + ray->line_height / 2)
		* texture->height / ray->line_height;
	if (ray->tex_y < 0)
		ray->tex_y = 0;
	if (ray->tex_y >= (int)texture->height)
		ray->tex_y = texture->height - 1;
}
