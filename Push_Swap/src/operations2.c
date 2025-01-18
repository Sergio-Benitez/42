/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:53:27 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/19 00:33:30 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	first = *stack_a;
	second = (*stack_a)->next;
	*stack_a = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	ft_recalculate(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	first = *stack_b;
	second = (*stack_b)->next;
	*stack_b = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_recalculate(stack_b);
	ft_printf("sb\n");
}

void	ft_rra(t_node **stack_a, int flag)
{
	t_node	*last;
	t_node	*second_last;

	second_last = *stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_recalculate(stack_a);
	if (!flag)
		ft_printf("rra\n");
}

void	ft_rrb(t_node **stack_b, int flag)
{
    t_node	*last;
    t_node	*second_last;

	second_last = *stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_recalculate(stack_b);
	if (!flag)
		ft_printf("rrb\n");
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	ft_printf("rrr\n");
}
