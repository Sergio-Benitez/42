/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/17 03:17:35 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_recalculate(t_node **stack)
{
	ft_get_stacksize(stack);
	ft_getpos(stack);
}

void	ft_get_stacksize(t_node **stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *stack;
	while (*stack)
	{
		*stack = (*stack)->next;
		i++;
	}
	*stack = temp;
	while (*stack)
	{
		(*stack)->size = i;
		*stack = (*stack)->next;
	}
	*stack = temp;
}
