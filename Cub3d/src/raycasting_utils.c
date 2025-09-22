/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/03 18:05:11 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

static void	dda_step(t_game *game, t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
	if (ray->map_x < 0 || ray->map_y < 0
		|| ray->map_x >= game->map_width || ray->map_y >= game->map_height
		|| ray->map_x >= (int)ft_strlen(game->map[ray->map_y])
		|| game->map[ray->map_y][ray->map_x] == '1')
		ray->hit = 1;
}

static void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
}

void	ft_perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
		dda_step(game, ray);
	calculate_wall_distance(game, ray);
}

void	ft_calculate_draw_limits(t_ray *ray, int win_height)
{
	ray->line_height = (int)(win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + win_height / 2;
	if (ray->draw_end >= win_height)
		ray->draw_end = win_height - 1;
}
