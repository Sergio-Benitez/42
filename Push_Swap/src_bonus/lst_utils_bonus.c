/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:39:08 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/28 13:10:34 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

t_node	*ft_newnode(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->position = -1;
	new_node->target_pos = -1;
	new_node->size = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_pushnode(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = ft_newnode(value);
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

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

int	ft_is_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
