/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:49:58 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/20 22:51:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	n;

	n = 0;
	while (n * n <= nb)
	{
		if (n * n == nb)
			return (n);
		else
			n++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_sqrt(64));
	return (0);
}*/
