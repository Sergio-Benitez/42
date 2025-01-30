/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:40:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/27 20:41:30 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_init(t_node **stack_a, int size, long long **llong_array)
{
	int	i;

	i = size;
	while (i-- > 0)
		ft_pushnode(stack_a, (int)(*llong_array)[i]);
	if (!ft_sort_llongtab(*llong_array, size))
		return ;
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
	if (argc < 2)
		exit (0);
	llong_array = ft_check_args(argv, &size);
	ft_init(&stack_a, size, &llong_array);
	if (stack_a->size == 1)
		ft_free_exit(&stack_a, &stack_b, llong_array);
	else if (stack_a->size == 2 || stack_a->size == 3)
		ft_sort_three(&stack_a);
	else if (stack_a->size > 3)
		ft_push_swap(&stack_a, &stack_b);
	ft_free_exit(&stack_a, &stack_b, llong_array);
	return (0);
}
