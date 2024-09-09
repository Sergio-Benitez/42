/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:26:39 by labderra          #+#    #+#             */
/*   Updated: 2024/03/21 14:07:32 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_sq_value(struct s_map map, int i)
{
	int	x;
	int	y;
	int	size;

	size = 1;
	while (1)
	{
		y = 0;
		while (y < size)
		{
			x = 0;
			while (x < size)
			{
				if (map.board[i + x + (map.line_len * y)] == map.c_obst
					|| (x + i) >= (map.line_len - 2)
					|| i + (y * map.line_len) >= ft_strlen(map.board))
					return (size - 1);
				x++;
			}
			y++;
		}
		size ++;
	}
	return (0);
}

struct s_map	ft_print_solution(struct s_map map, int i, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			map.board[i + x +(map.line_len * y)] = map.c_full;
			x++;
		}
		y++;
	}
	return (map);
}

struct s_map	ft_solve(struct s_map map)
{
	int	i;
	int	len;
	int	pos_max;
	int	val_max;

	i = 0;
	len = ft_strlen(map.board);
	while (i < len)
	{
		if (ft_sq_value(map, i) > val_max)
		{
			val_max = ft_sq_value(map, i);
			pos_max = i;
		}
		i++;
	}
	map = ft_print_solution(map, pos_max, val_max);
	return (map);
}
