/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:33:36 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/25 20:13:08 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_pos(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->data[y][x] == 'P')
			{
				map->player_y = y;
				map->player_x = x;
			}
			else if (map->data[y][x] == 'E')
			{
				map->exit_y = y;
				map->exit_x = x;
			}
		}
	}
}

t_map	*get_map(char **map_data, char *file)
{
	t_map	*map;
	int		i;

	if (!map_data || !map_data[0])
		return (NULL);
	i = 0;
	while (map_data[i])
		i++;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->filename = file;
	map->width = ft_strlen(map_data[0]);
	map->width_px = map->width * TILE_SIZE;
	map->height = i;
	map->height_px = map->height * TILE_SIZE;
	map->data = map_data;
	map->player_n = 0;
	map->exit_n = 0;
	map->collect_n = 0;
	find_pos(map);
	return (map);
}

t_map	*load_create_map(char *file)
{
	int		fd;
	char	*strmap;
	char	**map_data;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError opening file");
		exit (1);
	}
	strmap = ft_calloc(100000, sizeof(char));
	if (!strmap)
		return (close(fd), NULL);
	read(fd, strmap, 99999);
	close(fd);
	map_data = ft_split(strmap, '\n');
	free(strmap);
	if (!map_data)
		return (NULL);
	map = get_map(map_data, file);
	if (!map || !check_map(map))
		return (ft_free_exit(map_data, map), NULL);
	return (map);
}

void	ft_free_exit(char **map_data, t_map *map)
{
	int	i;

	i = 0;
	if (map_data)
	{
		while (i < map->height)
		{
			free(map_data[i]);
			i++;
		}
		free(map_data);
	}
	if (map)
		free(map);
	exit (1);
}

void	flood_fill(t_map *map, char **map_data, int y, int x)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width
		|| map_data[y][x] == '1' || map_data[y][x] == 'X')
		return ;
	map_data[y][x] = 'X';
	flood_fill(map, map_data, y - 1, x);
	flood_fill(map, map_data, y + 1, x);
	flood_fill(map, map_data, y, x - 1);
	flood_fill(map, map_data, y, x + 1);
}

char	**copy_map_data(char **data, int height, int width)
{
	char	**copy;
	int		y;
	int		x;

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	y = 0;
	while (y < height)
	{
		copy[y] = malloc(sizeof(char) * (width + 1));
		if (!copy[y])
			return (NULL);
		x = 0;
		while (x < width)
		{
			copy[y][x] = data[y][x];
			x++;
		}
		copy[y][x] = '\0';
		y++;
	}
	return (copy);
}

void	free_map_data(char **aux, int height)
{
	while (--height >= 0)
		free(aux[height]);
	free(aux);
}
