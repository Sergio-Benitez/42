/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:56:47 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/28 16:57:49 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_get_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_b->cost_b = temp_b->position;
		if (temp_b->position > temp_b->size / 2)
			temp_b->cost_b = (temp_b->size - temp_b->position) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > temp_a->size / 2)
			temp_b->cost_a = (temp_a->size - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

void	ft_move(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_do_rrr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_do_rr(stack_a, stack_b, &cost_a, &cost_b);
	ft_do_ra(stack_a, &cost_a);
	ft_do_rb(stack_b, &cost_b);
	ft_pa(stack_a, stack_b);
}

void	ft_move_cheapest(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (ft_abs(temp->cost_a) + ft_abs(temp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(temp->cost_b) + ft_abs(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	ft_move(stack_a, stack_b, cost_a, cost_b);
}

void	ft_shift_stack(t_node **stack_a)
{
	int	lowest_pos;

	lowest_pos = ft_get_lowestidxpos(stack_a);
	if (lowest_pos > (*stack_a)->size / 2)
	{
		while (lowest_pos < (*stack_a)->size)
		{
			ft_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_ra(stack_a);
			lowest_pos--;
		}
	}
}
