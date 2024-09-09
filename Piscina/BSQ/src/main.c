/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:04:10 by labderra          #+#    #+#             */
/*   Updated: 2024/03/21 14:00:59 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int				i;
	char			*file_name;
	struct s_map	map;

	if (argc < 2)
	{
		file_name = ft_keyb_entry();
		map = ft_map(file_name);
		if (map.board != NULL)
			write(1, map.board, ft_strlen(map.board));
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map = ft_map(argv[i]);
			if (map.board != NULL)
				write(1, map.board, ft_strlen(map.board));
			i++;
		}
	}
	return (0);
}
