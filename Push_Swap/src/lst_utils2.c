/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/23 14:11:02 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_three(t_node **stack)
{
	int		highest;
	t_node	*first;

	highest = (*stack)->index;
	first = *stack;
	while (*stack)
	{
		if ((*stack)->index > highest)
			highest = (*stack)->index;
		*stack = (*stack)->next;
	}
	*stack = first;
	if ((*stack)->index == highest)
		ft_ra(stack, 0);
	else if ((*stack)->next->index == highest)
		ft_rra(stack, 0);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

void	ft_pb_all(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = (*stack_a)->size;
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a, 0);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		ft_pb(stack_a, stack_b);
		pushed++;
	}
}

int	ft_get_target(t_node **a, int b_idx, int target_idx, int target_pos)
{
	t_node	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	ft_get_targetpos(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_b;
	int		target_pos;

	temp_b = *stack_b;
	target_pos = 0;
	while (temp_b)
	{
		target_pos = ft_get_target(stack_a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_pos = target_pos;
		temp_b = temp_b->next;
	}
}

void	ft_push_swap(t_node **stack_a, t_node **stack_b)
{
	ft_pb_all(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_get_targetpos(stack_a, stack_b);
		ft_get_cost(stack_a, stack_b);
		break;
//		do_cheapest_move(stack_a, stack_b);
	}
//	if (!ft_is_sorted(*stack_a))
//		shift_stack(stack_a);
}
