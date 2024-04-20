/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:14:22 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/14 16:05:21 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	no_espace(char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	res;

	neg = 0;
	res = 0;
	while (no_espace(str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '+')
			str++;
		else
		{
			neg++;
			str++;
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (neg % 2 != 0)
		res = res * -1;
	return (res);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "You must introduce 2 arguments", 30);
		return (0);
	}
	else
		printf("%d", ft_atoi(argv[1]));
	return (0);
}*/
