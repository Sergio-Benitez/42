/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:21:36 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/29 20:23:16 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	ft_free_llongarray(long long *array, int flag)
{
	free(array);
	if (!flag)
	{
		ft_putendl_fd("Error", 2);
		exit (1);
	}
}

void	ft_free_matrix(char **matrix, int flag)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	if (!flag)
	{
		ft_putendl_fd("Error", 2);
		exit (1);
	}
}

void	ft_free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	ft_free_exit(t_node **stack_a, t_node **stack_b, long long *array)
{
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	if (array)
		free(array);
	exit (0);
}

void	ft_free_ssi(t_node **a, t_node **b, char **i)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	if (i)
		ft_free_matrix(i, 1);
	exit (1);
}
