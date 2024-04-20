/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:46:57 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/20 22:49:36 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1 || index == 2)
		return (1);
	else if (index > 2)
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_fibonacci(8));
	return (0);
}*/
