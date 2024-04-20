/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:54:48 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/20 22:59:42 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	c;

	c = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (c < nb)
	{
		if (nb % c == 0)
			return (0);
		c++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = 0;
	while (i <= 20)
	{
		printf("%d\n", ft_is_prime(i));
		i++;
	}
	return (0);
}*/
