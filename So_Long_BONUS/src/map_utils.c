/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:33:36 by sbenitez          #+#    #+#             */
/*   Updated: 2024/11/11 13:23:26 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_pos(t_map *map)
{
	int	y;
	int	x;
	int	collect_index;

	y = -1;
	collect_index = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->data[y][x] == 'P')
			{
				map->player_pos.y = y;
				map->player_pos.x = x;
			}
			else if (map->data[y][x] == 'E')
			{
				map->exit_pos.y = y;
				map->exit_pos.x = x;
			}
			else if (map->data[y][x] == 'S')
			{
				map->enemy_pos.y = y;
				map->enemy_pos.x = x;
			}
			else if (map->data[y][x] == 'C')
            {
				if (collect_index < map->collect_n)
                {
                    map->collect_pos[collect_index].x = x;
                    map->collect_pos[collect_index].y = y;
                    collect_index++;
                }
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
	update_flags(map);
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
	strmap = ft_calloc(1000000, sizeof(char));
	if (!strmap)
		return (close(fd), NULL);
	read(fd, strmap, 999999);
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
