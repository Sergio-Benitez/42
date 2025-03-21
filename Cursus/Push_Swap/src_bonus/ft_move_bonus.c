/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:30:10 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/28 16:57:08 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	ft_do_rrr(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(stack_a, stack_b);
	}
}

void	ft_do_rr(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(stack_a, stack_b);
	}
}

void	ft_do_ra(t_node **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rra(stack_a);
			(*cost)++;
		}
	}
}

void	ft_do_rb(t_node **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrb(stack_b);
			(*cost)++;
		}
	}
}
