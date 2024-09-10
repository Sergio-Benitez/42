/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:54:24 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/10 13:30:06 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map *map)
{
	if (!(check_frame(map) || check_chars(map) || check_path(map)))
		return (write(2, "Error\nInvalid map.", 18), 0);
	return (1);
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
			write(2, "Error\nRows must be the same length.\n", 36);
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
		perror("Error\nError opening file");
		exit (1);
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
	if (argc != 2)
	{
		if (argc == 1)
			return (write(2, "Error\nEnter a map to run.\n", 26), 1);
		else
			return (write(2, "Error\nToo many arguments.\n", 26), 1);
	}
	check_extension(argv[1]);
	t_map	*map = get_struct(load_create_map(argv[1])); //borrar
	check_map(map);
	return (0);
}
