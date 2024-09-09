/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:54:24 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/09 22:04:25 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_map(char **map)
{
	
}

t_map	*get_struct(char **map_data)
{
	int		i;
	t_map	*map;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	while (map_data[i])
	{
		if (ft_strlen(map_data[0]) != ft_strlen(map_data[i]))
		{
			write(2, "Rows must be the same length.\n", 30);
			free(map);
			exit (1);
		}
		i++;
	}
	map->width = ft_strlen(map_data[0]);
	map->height = i;
	map->data = map_data;
	return (map);
}

char	**load_create_map(char *file)
{
	int		fd;
	char	*strmap;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file.\n");
		return (0);
	}
	strmap = ft_calloc(100000, sizeof(char));
	read(fd, strmap, 99999);
	close(fd);
	map = ft_split(strmap, '\n');
	free(strmap);
	return (map);
}

int	main(int argc, char **argv)
{
	int i = 0;
//	Verificar si el archivo es .ber	
	if (argc != 2)
	{
		write(1, "Mete archivo, cabrón.\n", 23);
		return (1);
	}
/*
	char	**map_data = load_create_map(argv[1]);
	while (map[i])
		printf("%s\n", map[i++]);
*/
	t_map	*map = get_struct(load_create_map(argv[1]));
	while (i < map->height)
	{
		printf("%s\n", map->data[i++]);
	}
	return (0);
}