/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/02 23:45:17 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_first_line(char **temp_map, char *first_line, int *map_lines)
{
	if (first_line && ft_strlen(first_line) > 1 && first_line[0] != '\n')
	{
		temp_map[*map_lines] = ft_strtrim(first_line, "\n");
		if (!temp_map[*map_lines])
		{
			free(first_line);
			return (-1);
		}
		(*map_lines)++;
	}
	if (first_line)
		free(first_line);
	return (0);
}

static int	read_map_lines(int fd, char **temp_map, int *map_lines)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1 && line[0] != '\n')
		{
			temp_map[*map_lines] = ft_strtrim(line, "\n");
			if (!temp_map[*map_lines])
			{
				free(line);
				return (-1);
			}
			(*map_lines)++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

static void	setup_game_map(t_game *game, char **temp_map, int map_lines)
{
	int	i;

	i = 0;
	while (i < map_lines)
	{
		game->map[i] = temp_map[i];
		if ((int)ft_strlen(game->map[i]) > game->map_width)
			game->map_width = (int)ft_strlen(game->map[i]);
		i++;
	}
	game->map[i] = NULL;
}

int	ft_parse_map_with_first_line(int fd, t_game *game, char *first_line)
{
	char	**temp_map;
	int		map_lines;

	map_lines = 0;
	temp_map = malloc(sizeof(char *) * 1000);
	if (!temp_map)
		return (-1);
	if (add_first_line(temp_map, first_line, &map_lines) == -1)
		return (-1);
	if (read_map_lines(fd, temp_map, &map_lines) == -1)
		return (-1);
	temp_map[map_lines] = NULL;
	game->map_height = map_lines;
	game->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!game->map)
		return (-1);
	setup_game_map(game, temp_map, map_lines);
	free(temp_map);
	return (0);
}
