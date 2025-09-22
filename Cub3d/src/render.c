/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/03 18:05:11 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_frame(void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (y < game->win_height / 2)
				ft_put_pixel(game, x, y, game->tex.ceiling_color);
			else
				ft_put_pixel(game, x, y, game->tex.floor_color);
			x++;
		}
		y++;
	}
	ft_raycasting(game);
}

void	ft_draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	int			y;
	uint32_t	color;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		color = ft_get_texture_color(game, ray, y);
		ft_put_pixel(game, x, y, color);
		y++;
	}
}

uint32_t	ft_get_texture_color(t_game *game, t_ray *ray, int y)
{
	mlx_texture_t	*texture;
	uint32_t		color;

	texture = ft_get_wall_texture(game, ray);
	ft_calculate_texture_coords(game, ray, texture, y);
	color = *(uint32_t *)(texture->pixels
			+ (ray->tex_y * texture->width + ray->tex_x) * 4);
	return (color);
}

void	ft_put_pixel(t_game *game, int x, int y, uint32_t color)
{
	if (x >= 0 && x < game->win_width && y >= 0 && y < game->win_height)
		mlx_put_pixel(game->img, x, y, color);
}
