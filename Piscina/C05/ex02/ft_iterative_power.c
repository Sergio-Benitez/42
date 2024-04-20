/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:41:25 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/20 22:53:54 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	power_r;

	power_r = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		power_r = power_r * nb;
		power--;
	}
	return (power_r);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_power(2, 3));
	return (0);
}*/
