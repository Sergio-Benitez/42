/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:33:36 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/11 23:19:14 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map->height = i;
	map->data = map_data;
	map->player_n = 0;
	map->exit_n = 0;
	map->collect_n = 0;
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

void	flood_fill(t_map *map, char n)
{
	t_map	*aux;

	aux = map;
}
