/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:51:46 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/04 15:42:32 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 8;
	b = 5;
	ft_swap(&a, &b);
	printf ("%d %d", a, b);
	return (0);
}*/
