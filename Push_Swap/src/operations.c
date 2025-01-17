/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:12:07 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/17 03:27:18 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	ft_recalculate(stack_a);
	ft_recalculate(stack_b);}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!*stack_b)
	{
		temp = (*stack_a)->next;
		*stack_b = *stack_a;
		(*stack_b)->next = NULL;
		*stack_a = temp;
	}
	else
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp;
	}
	ft_recalculate(stack_a);
	ft_recalculate(stack_b);
}
