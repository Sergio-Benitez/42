/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:56:47 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/23 14:30:14 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_absolutize(int nb)
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