/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:17:16 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/29 20:15:16 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LLONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			return (LLONG_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

long long	*ft_llongize_args(char **clean_args, int size)
{
	long long	*llong_array;
	int			i;

	llong_array = (long long *)malloc(size * sizeof(long long));
	if (!llong_array)
		return (ft_putendl_fd("Error\nMemory allocation failed.\n", 2), NULL);
	i = 0;
	while (i < size)
	{
		llong_array[i] = ft_atoll(clean_args[i]);
		i++;
	}
	return (llong_array);
}
