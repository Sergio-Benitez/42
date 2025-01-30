/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:12:07 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/30 13:36:07 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	ft_get_stacksize(stack_a);
	if (!(*stack_b))
	{
		free(*stack_b);
		stack_b = NULL;
	}
	else
		ft_get_stacksize(stack_b);
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_a || !*stack_a)
		return ;
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
	ft_get_stacksize(stack_a);
	ft_get_stacksize(stack_b);
}

void	ft_ra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*first;

	if (!stack_a || !*stack_a || (*stack_a)->size < 2)
		return ;
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

	if (!stack_b || !*stack_b || (*stack_b)->size < 2)
		return ;
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
	if (!stack_a || !*stack_a || (*stack_a)->size < 2 || !stack_b
		|| !*stack_b || (*stack_b)->size < 2)
		return ;
	ft_ra(stack_a);
	ft_rb(stack_b);
}
