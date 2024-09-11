/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:33:36 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/11 02:04:57 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*get_map(char **map_data, char *file)
{
	t_map	*map;
	int		i;

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

void	ft_free_exit(char *strmap, t_map *map)
{
	if (strmap)
		free(strmap);
	if (map)
	{
		if (map->height > 0)
		{
			free(map->data[map->height - 1]);
			map->height--;
			ft_free_exit(NULL, map);
			return ;
		}
		free(map->data);
		free(map);
	}
	exit (1);
}
