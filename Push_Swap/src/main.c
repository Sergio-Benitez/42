/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:40:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/13 19:34:15 by sbenitez         ###   ########.fr       */
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
	int 	i;
	t_node	*stack_a;

	stack_a = NULL;
	i = argc - 1;
	(void)i;

/* 	int j = 1;
	while (argv[j])
	{
		ft_printf("%s\n", argv[j]);
		j++;
	} */


	if (argc < 2) // no params = return control w/ msg
		return (0);
	if (!ft_check_args(argv, &stack_a)) // Error\n = check_int, check_><intmax intmin, check_dup
		return (0);
/* 	while (i > 0)
	{
		ft_pushnode(&stack_a, ft_atoi(argv[i]));
		i--;
	} */
	ft_print_stack(stack_a);
	return (0);
}