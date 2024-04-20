/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:24:27 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/20 22:37:28 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	f;

	f = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		f = f * nb;
		nb = nb - 1;
	}
	return (f);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_factorial(5));
}*/
