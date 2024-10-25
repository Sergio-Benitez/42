/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:54:24 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/25 12:17:20 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map *map)
{
	if (!(check_type(map->filename)))
		return (write(2, "Error\nInvalid file extension.\n", 30), 0);
	if (!(check_chars(map)))
	{
		if (map->player_n == 0)
			write(2, "Error\nNo 'Player' found.\n", 25);
		if (map->player_n > 1)
			write(2, "Error\nToo many 'Players' found.\n", 32);
		if (map->exit_n == 0)
			write(2, "Error\nNo 'Exit' found.\n", 23);
		if (map->exit_n > 1)
			write(2, "Error\nToo many 'Exits' found.\n", 30);
		if (map->collect_n == 0)
			write(2, "Error\nNo 'Collectables' found.\n", 31);
		return (0);
	}
	if (!(check_rect(map->data)))
		return (write(2, "Error\nMap must be rectangular.\n", 31), 0);
	if (!(check_frame(map)))
		return (write(2, "Error\nFrame is not correctly closed.\n", 37), 0);
	if (!(check_path(map)))
		return (write(2, "Error\nInvalid path.\n", 20), 0);
	return (1);
}
/*
int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	if (argc != 2)
	{
		if (argc == 1)
			return (write(2, "Error\nEnter a map to run.\n", 26), 1);
		else
			return (write(2, "Error\nToo many arguments.\n", 26), 1);
	}
	i = 0;
	map = load_create_map(argv[1]);
	while (map->data[i])
		printf("%s\n", map->data[i++]);
	return (ft_free_exit(map->data, map), 0);
}
*/