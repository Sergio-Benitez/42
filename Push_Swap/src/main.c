/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:40:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/15 18:37:55 by sbenitez         ###   ########.fr       */
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
void	ft_init(t_node **stack_a, int size, long long **llong_array)
{
	int	i;
	
	i = size;
	while (i-- > 0)
		ft_pushnode(stack_a, (int)(*llong_array)[i]);
	if (!ft_sort_llongtab(*llong_array, size))
		(ft_printf("Arguments are already sorted.\n"), exit (0));
	ft_get_index(*llong_array, stack_a, size);
	ft_getpos(stack_a);
}

int	main(int argc, char **argv)
{
	int			size;
	long long	*llong_array;
	t_node		*stack_a;
//	t_node		*stack_b;

	stack_a = NULL;
//	stack_b = NULL;
	size = 0;
	if (argc < 2)
		return (0);
	llong_array = ft_check_args(argv, &size);
	if (!llong_array)
		return (0);
	ft_init(&stack_a, size, &llong_array);
	ft_print_stack(stack_a);
//	CREAR FUNCIÓN PARA HACER FREES
	ft_free_stack(&stack_a);
	free(llong_array);
	return (0);
}
