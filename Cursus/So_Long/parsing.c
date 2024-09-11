/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:54:24 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/11 01:55:44 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map *map)
{
	if (!(check_type(map->filename)))
		return (write(2, "Error\nInvalid file extension.\n", 31), 0);
	if (!(check_chars(map)))
		return (write(2, "Error\nInvalid characters in map.\n", 35), 0);
	if (!(check_rect(map->data)))
		return (write(2, "Error\nMap must be rectangular.\n", 33), 0);
	if (!(check_frame(map)))
		return (write(2, "Error\nFrame is not valid.\n", 28), 0);
	if (!(check_path(map)))
		return (write(2, "Error\nInvalid path.\n", 21), 0);
	return (1);
}

t_map	*load_create_map(char *file)
{
	int		fd;
	char	*strmap;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError opening file");
		exit (1);
	}
	strmap = ft_calloc(100000, sizeof(char));
	if (!strmap)
		return (NULL);
	read(fd, strmap, 99999);
	close(fd);
	map = get_map(ft_split(strmap, '\n'), file);
	if (!map || !check_map(map))
		ft_free_exit(strmap, map);
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
	t_map	*map = load_create_map(argv[1]);
	int i = 0;
	while (i < map->height)
			printf("%s\n", map->data[i++]);
	return (0);
}
