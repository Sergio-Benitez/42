/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/03 18:13:37 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_texture_section(int fd, t_game *game, char **last_line)
{
	char	*line;
	int		texture_count;

	texture_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1 && line[0] != '\n')
		{
			if (ft_parse_resolution(line, game) == 1)
				continue ;
			else if (ft_parse_sprite(line, game) == 1)
				continue ;
			else if (ft_parse_textures(line, game) == 1)
				texture_count++;
			else if (ft_parse_colors(line, game) == 1)
				texture_count++;
			else if (texture_count >= 6)
				break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	*last_line = line;
	return (texture_count);
}

int	ft_parse_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		texture_count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	texture_count = parse_texture_section(fd, game, &line);
	if (texture_count < 6)
		return (close(fd), -1);
	if (ft_parse_map_with_first_line(fd, game, line) == -1)
		return (close(fd), -1);
	close(fd);
	return (0);
}

int	ft_parse_textures(char *line, t_game *game)
{
	char	**split;

	split = ft_split_and_trim(line, ' ');
	if (!split || !split[0] || !split[1])
		return (ft_free_split(split), 0);
	if (ft_strncmp(split[0], "NO", 3) == 0 && !game->tex.north)
		game->tex.north = (mlx_texture_t *)1;
	else if (ft_strncmp(split[0], "SO", 3) == 0 && !game->tex.south)
		game->tex.south = (mlx_texture_t *)1;
	else if (ft_strncmp(split[0], "WE", 3) == 0 && !game->tex.west)
		game->tex.west = (mlx_texture_t *)1;
	else if (ft_strncmp(split[0], "EA", 3) == 0 && !game->tex.east)
		game->tex.east = (mlx_texture_t *)1;
	else
		return (ft_free_split(split), 0);
	ft_free_split(split);
	return (1);
}

int	ft_parse_resolution(char *line, t_game *game)
{
	char	**split;
	int		width;
	int		height;

	if (game->win_width != 0 || game->win_height != 0)
		return (0);
	split = ft_split_and_trim(line, ' ');
	if (!split || !split[0] || !split[1] || !split[2])
		return (ft_free_split(split), 0);
	if (ft_strncmp(split[0], "R", 2) != 0)
		return (ft_free_split(split), 0);
	width = ft_atoi(split[1]);
	height = ft_atoi(split[2]);
	if (width <= 0 || height <= 0)
		return (ft_free_split(split), -1);
	game->win_width = width;
	game->win_height = height;
	ft_free_split(split);
	return (1);
}

int	ft_parse_sprite(char *line, t_game *game)
{
	char	**split;

	(void)game;
	split = ft_split_and_trim(line, ' ');
	if (!split || !split[0] || !split[1])
		return (ft_free_split(split), 0);
	if (ft_strncmp(split[0], "S", 2) != 0)
		return (ft_free_split(split), 0);
	ft_free_split(split);
	return (1);
}
