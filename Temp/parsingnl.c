/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:41:03 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/06 20:35:15 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solongnl.h"

void	check_map()
{
	
}

char	**load_create_map(char *file)
{
	char	*row;
	char	**map;
	int		fd;
	int		i;
	
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (0);
	}
	while((row = get_next_line(fd)) != NULL)
	{
		map[i++] = row;
		free(row);
	}
	close (fd);
	return (map);
}

int	main(int argc, char **argv)
{
	int i = 0;
	if (argc < 2)
	{
		write(1, "Mete archivo, cabrón.", 21);
		return (1);
	}
	char **map = load_create_map(argv[1]);
	while (map[i])
		printf("%s\n", map[i++]);
	return (0);
}