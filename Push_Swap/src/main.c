/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:40:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/17 03:31:14 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print_stack(t_node *stack)
{
	if (!stack)
	{
		ft_printf("Stack B: vacío.\n");
		return ;
	}
	while (stack)
	{
		ft_printf("Value: %d, Index: %d, Position: %d, Size = %d, Target Pos: %d\n\n",
			stack->value, stack->index, stack->position, stack->size, stack->target_pos);
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
	ft_get_stacksize(stack_a);
}

int	main(int argc, char **argv)
{
	int			size;
	long long	*llong_array;
	t_node		*stack_a;
	t_node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc < 3)
		exit (0);
	llong_array = ft_check_args(argv, &size);
	if (!llong_array)
		exit (1);
	ft_init(&stack_a, size, &llong_array);
	ft_printf("STACK A:\n\n");
	ft_print_stack(stack_a);
	ft_printf("HACEMOS PB hasta que queden 3 en STAcK A:\n\n");
	while (stack_a->size > 3)
		ft_pb(&stack_a, &stack_b);
	ft_printf("STACK A:\n\n");
	ft_print_stack(stack_a);
	ft_printf("STACK B:\n\n");
	ft_print_stack(stack_b);
	ft_printf("HACEMOS PA:\n\n");
	ft_pa(&stack_a, &stack_b);
	ft_printf("STACK A:\n\n");
	ft_print_stack(stack_a);
	ft_printf("STACK B:\n\n");
	ft_print_stack(stack_b);
	ft_free_exit(&stack_a, NULL, llong_array);
	return (0);
}
