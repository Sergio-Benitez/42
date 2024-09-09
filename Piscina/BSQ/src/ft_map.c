/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:05:43 by labderra          #+#    #+#             */
/*   Updated: 2024/03/21 14:00:01 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_map_lines(char *map, int n_lines)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = -1;
	while (map[i] != '\n')
		i++;
	j = i + 1;
	while (map[j] != '\0')
	{
		while (map[j] != '\n' && n_lines > 2)
			j++;
		n_lines--;
		if (len == -1)
			len = j - i;
		else
		{
			if ((j - i) % len != 0)
				return (0);
		}
		j++;
	}
	ft_strtrim(map, i + 1);
	return (len - 1);
}

int	ft_get_symbols(char	*map, char *c_free, char *c_obst, char *c_full)
{
	int		i;
	int		j;
	char	*first_line;

	i = 0;
	j = 0;
	while (map[i] != '\n')
		i++;
	if (i < 4)
		return (-1);
	first_line = malloc(sizeof(char) * (i + 1));
	if (first_line == NULL)
		ft_error("error\n");
	*c_full = map[i - 1];
	*c_obst = map[i - 2];
	*c_free = map[i - 3];
	return (ft_atoi(ft_strclip(first_line, map, i - 3)));
}

struct s_map	ft_map(char *str)
{
	struct s_map	map;

	map.n_lines = 0;
	map.line_len = 0;
	map.board = malloc(sizeof(char) * ft_file_size(str, &map.n_lines));
	if (map.board == NULL)
		ft_error("error\n");
	if (ft_file_load(str, map.board) == -1)
		ft_error("error\n");
	if ((ft_get_symbols(map.board, &map.c_free, &map.c_obst, &map.c_full)
			!= map.n_lines - 2) || map.c_free == map.c_obst
		|| map.c_free == map.c_full || map.c_full == map.c_obst
		|| ft_check_map_lines(map.board, map.n_lines) == 0)
	{
		write(1, "map error\n", 10);
		map.board = NULL;
	}
	map.line_len = ft_strlen(map.board) / (map.n_lines - 2);
	return (ft_solve(map));
}
