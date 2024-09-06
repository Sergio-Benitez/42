/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:54:24 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/06 19:30:25 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_map()
{
	
}

char	**create_map(char *strmap)
{
	char	**map;
	map = ft_split(strmap, '\n');
	return (map);
}

char	*load_map(char *file)
{
	int		fd;
	char	*strmap;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (0);
	}
	strmap = ft_calloc(231, sizeof(char));
	read(fd, strmap, 230); // 15*15 = 225, +5 chars extra
	close(fd);
	return (strmap);
}

int	main(int argc, char **argv)
{
	int i = 0;
	if (argc < 2)
	{
		write(1, "Mete archivo, cabrón.", 21);
		return (1);
	}
	char **map = create_map(load_map(argv[1]));
	while (map[i])
		printf("%s\n", map[i++]);
	return (0);
}