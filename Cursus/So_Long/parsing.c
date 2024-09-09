/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:54:24 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/09 13:51:03 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_map(char **map)
{
	
}

char	**load_create_map(char *file)
{
	int		fd;
	char	*strmap;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (0);
	}
	strmap = ft_calloc(100000, sizeof(char));
	read(fd, strmap, 99999); // 15*15 = 225, +5 chars extra
	close(fd);
	map = ft_split(strmap, '\n');
	free(strmap);
	return (map);
}

int	main(int argc, char **argv)
{
	int i = 0;
//	Verificar si el archivo es .ber	
	if (argc < 2)
	{
		write(1, "Mete archivo, cabrón.\n", 23);
		return (1);
	}
	
	char **map = load_create_map(argv[1]);
	while (map[i])
		printf("%s\n", map[i++]);
	return (0);
}