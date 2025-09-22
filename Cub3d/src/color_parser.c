/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/02 23:45:17 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_floor_color(char **split, t_game *game)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(split[1], ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (ft_free_split(rgb), -1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_free_split(rgb), -1);
	game->tex.floor_color = ft_get_color_from_rgb(r, g, b);
	ft_free_split(rgb);
	return (1);
}

static int	parse_ceiling_color(char **split, t_game *game)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(split[1], ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (ft_free_split(rgb), -1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_free_split(rgb), -1);
	game->tex.ceiling_color = ft_get_color_from_rgb(r, g, b);
	ft_free_split(rgb);
	return (1);
}

int	ft_parse_colors(char *line, t_game *game)
{
	char	**split;
	int		result;

	split = ft_split_and_trim(line, ' ');
	if (!split || !split[0] || !split[1])
		return (ft_free_split(split), 0);
	if (ft_strncmp(split[0], "F", 2) == 0 && game->tex.floor_color == 0)
		result = parse_floor_color(split, game);
	else if (ft_strncmp(split[0], "C", 2) == 0 && game->tex.ceiling_color == 0)
		result = parse_ceiling_color(split, game);
	else
		result = 0;
	ft_free_split(split);
	if (result == -1)
		return (-1);
	return (result);
}
