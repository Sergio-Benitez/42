/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:37:51 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/02 23:55:12 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point current, char target)
{
	if (current.y < 0 || current.y >= size.y || current.x < 0 || current.x >= size.x || tab[current.y][current.x] != target)
		return;
	tab[current.y][current.x] = 'F';
	fill(tab, size, (t_point){current.x - 1, current.y}, target);
	fill(tab, size, (t_point){current.x + 1, current.y}, target);
	fill(tab, size, (t_point){current.x, current.y - 1}, target);
	fill(tab, size, (t_point){current.x, current.y + 1}, target);

}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}