/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/02 23:45:17 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture_file(t_game *game __attribute__((unused)),
	mlx_texture_t **texture, char *path)
{
	*texture = mlx_load_png(path);
	if (!*texture)
		return (-1);
	return (0);
}

static int	parse_texture_line(char *line, t_game *game)
{
	char	**split;
	int		result;

	split = ft_split_and_trim(line, ' ');
	if (!split || !split[0] || !split[1])
		return (ft_free_split(split), 0);
	result = 0;
	if (ft_strncmp(split[0], "NO", 3) == 0)
		result = load_texture_file(game, &game->tex.north, split[1]);
	else if (ft_strncmp(split[0], "SO", 3) == 0)
		result = load_texture_file(game, &game->tex.south, split[1]);
	else if (ft_strncmp(split[0], "WE", 3) == 0)
		result = load_texture_file(game, &game->tex.west, split[1]);
	else if (ft_strncmp(split[0], "EA", 3) == 0)
		result = load_texture_file(game, &game->tex.east, split[1]);
	else
		result = 0;
	ft_free_split(split);
	if (result == -1)
		return (-1);
	if (result == 0)
		return (1);
	return (0);
}

static int	process_texture_lines(int fd, t_game *game)
{
	char	*line;
	int		texture_count;
	int		result;

	texture_count = 0;
	line = get_next_line(fd);
	while (line && texture_count < 4)
	{
		if (ft_strlen(line) > 1 && line[0] != '\n')
		{
			result = parse_texture_line(line, game);
			if (result == 1)
				texture_count++;
			else if (result == -1)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (texture_count);
}

int	ft_load_textures(char *filename, t_game *game)
{
	int		fd;
	int		texture_count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	texture_count = process_texture_lines(fd, game);
	close(fd);
	if (texture_count == 4)
		return (0);
	if (texture_count == -1)
		return (-1);
	return (-1);
}
