/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:11:08 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/20 23:40:41 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	c;

	c = 2;
	while (c < nb)
	{
		if (nb % c == 0)
			return (0);
		c++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	c;

	c = nb;
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(c))
		c++;
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_is_prime(0));
	return (0);
}*/
