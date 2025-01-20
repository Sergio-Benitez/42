/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:25:31 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/20 20:17:04 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	if ((*stack)->size == 2)
	{
		ft_sa(stack);
		return ;
	}
	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first > second && second > third)
		(ft_sa(stack), ft_rra(stack, 0));
	else if (first > third && third > second)
		ft_ra(stack, 0);
	else if (second > first && first > third)
		ft_rra(stack, 0);
	else if (second > third && third > first)
		(ft_sa(stack), ft_ra(stack, 0));
	else if (third > first && first > second)
		ft_sa(stack);
}
