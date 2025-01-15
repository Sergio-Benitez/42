/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:17:16 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/15 18:35:19 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	ft_sort_llongtab(long long *tab, int size)
{
	int	i;
	int	j;
	int	temp;
	int	flag;

	i = 0;
	flag = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
				flag = 1;
			}
			j++;
		}
		i++;
	}
	return (flag);
}

void	ft_get_index(long long *tab, t_node **stack_a, int size)
{
	int		i;
	t_node	*temp;
	
	i = 0;
	temp = *stack_a;
	while (i < size)
	{
		while (*stack_a)
		{
			if ((*stack_a)->value == (int)tab[i])
				(*stack_a)->index = i;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = temp;
		i++;
	}
}

void	ft_getpos(t_node **stack)
{
	int	i;
	t_node	*temp;

	i = 0;
	temp = *stack;
	while (*stack)
	{
		i++;
		(*stack)->position = i;
		*stack = (*stack)->next;
	}
	*stack = temp;
}