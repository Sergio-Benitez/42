/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:39:08 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/13 16:57:46 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	new_node->next = NULL;
	return (new_node);
}

void	ft_pushnode(t_node **stack, int value)
{
	t_node *new_node;

	new_node = ft_newnode(value);
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}
