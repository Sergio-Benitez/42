/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:53:27 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/17 17:06:08 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack_a;
	second = (*stack_a)->next;
	third = second->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next = third;
	*stack_a = second;
	second->next = first;
	ft_recalculate(stack_a);
	ft_printf("sa\n");
}