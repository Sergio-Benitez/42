/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:54:59 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/13 15:08:52 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_comb2(int left, int right)
{
	char	digit;

	digit = '0' + left / 10;
	write(1, &digit, 1);
	digit = '0' + left % 10;
	write(1, &digit, 1);
	write(1, " ", 1);
	digit = '0' + right / 10;
	write(1, &digit, 1);
	digit = '0' + right % 10;
	write(1, &digit, 1);
}

void	ft_print_comb2(void)
{
	int	v_left;
	int	v_right;

	v_left = 0;
	while (v_left < 99)
	{
		v_right = v_left +1;
		while (v_right < 100)
		{
			ft_write_comb2(v_left, v_right);
			if (!(v_left == 98))
			{
				write(1, ", ", 2);
			}
			v_right ++;
		}
		v_left ++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
