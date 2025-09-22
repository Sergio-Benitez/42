/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/02 23:45:17 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	copy_temp_to_game(t_game *game, char **temp_map, int map_lines)
{
	int	i;

	game->map_height = map_lines;
	game->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!game->map)
		return (-1);
	i = 0;
	while (i < map_lines)
	{
		game->map[i] = temp_map[i];
		if ((int)ft_strlen(game->map[i]) > game->map_width)
			game->map_width = (int)ft_strlen(game->map[i]);
		i++;
	}
	game->map[i] = NULL;
	return (0);
}

static int	read_map_lines(int fd, char **temp_map)
{
	char	*line;
	int		map_lines;

	map_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1 && line[0] != '\n')
		{
			temp_map[map_lines] = ft_strtrim(line, "\n");
			if (!temp_map[map_lines])
			{
				free(line);
				return (-1);
			}
			map_lines++;
		}
		free(line);
		line = get_next_line(fd);
	}
	temp_map[map_lines] = NULL;
	return (map_lines);
}

int	ft_parse_map(int fd, t_game *game)
{
	char	**temp_map;
	int		map_lines;

	temp_map = malloc(sizeof(char *) * 1000);
	if (!temp_map)
		return (-1);
	map_lines = read_map_lines(fd, temp_map);
	if (map_lines == -1)
		return (-1);
	if (copy_temp_to_game(game, temp_map, map_lines) == -1)
		return (-1);
	free(temp_map);
	return (0);
}

int	ft_is_valid_element(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}
