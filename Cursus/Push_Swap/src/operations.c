/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:12:07 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/21 13:40:33 by sbenitez         ###   ########.fr       */
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
	ft_recalculate(stack_b);
	ft_printf("pa\n");
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
	ft_recalculate(stack_a);
	ft_recalculate(stack_b);
	ft_printf("pb\n");
}

void	ft_ra(t_node **stack_a, int flag)
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
	ft_recalculate(stack_a);
	if (!flag)
		ft_printf("ra\n");
}

void	ft_rb(t_node **stack_b, int flag)
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
	ft_recalculate(stack_b);
	if (!flag)
		ft_printf("rb\n");
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	ft_printf("rr\n");
}
