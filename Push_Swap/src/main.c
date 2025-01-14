/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:40:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/14 20:21:24 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("Value: %d, Index: %d, Position: %d, Target Position: %d\n",
			stack->value, stack->index, stack->position, stack->target_pos);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
//	t_node	*stack_b;

	stack_a = NULL;
	i = argc - 1;
	(void)i;
	if (argc < 2)
		return (0);
	if (!ft_check_args(argv, &stack_a))
		return (0);
	
	ft_print_stack(stack_a);
//	ft_free_stack(x) pa mañana xd
	return (0);
}
