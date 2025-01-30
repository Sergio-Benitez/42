/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:53:27 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/30 13:18:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	ft_sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if ((*stack_a)->size < 2)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	*stack_a = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}

void	ft_sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if ((*stack_b)->size < 2)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	*stack_b = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
}

void	ft_rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*second_last;

	if ((*stack_a)->size < 2)
		return ;
	second_last = *stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	ft_rrb(t_node **stack_b)
{
	t_node	*last;
	t_node	*second_last;

	if ((*stack_b)->size < 2)
		return ;
	second_last = *stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->size < 2
		|| !stack_b || !*stack_b || (*stack_b)->size < 2)
		return ;
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
