/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:12:07 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/29 20:15:59 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	if (!(*stack_b))
		free(*stack_b);
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = (*stack_a)->next;
	if (!*stack_b)
	{
		*stack_b = *stack_a;
		(*stack_b)->next = NULL;
		*stack_a = temp;
	}
	else
	{
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp;
	}
}

void	ft_ra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*first;

	temp = *stack_a;
	first = (*stack_a)->next;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->next == NULL)
		{
			(*stack_a)->next = temp;
			temp->next = NULL;
		}
	}
	*stack_a = first;
}

void	ft_rb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*first;

	temp = *stack_b;
	first = (*stack_b)->next;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		if ((*stack_b)->next == NULL)
		{
			(*stack_b)->next = temp;
			temp->next = NULL;
		}
	}
	*stack_b = first;
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
