/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:40:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/30 13:22:26 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	ft_init(t_node **stack_a, int size, long long **llong_array)
{
	int	i;

	i = size;
	while (i-- > 0)
		ft_pushnode(stack_a, (int)(*llong_array)[i]);
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
	else
	{
		ft_free_llongarray(llong_array, 1);
		llong_array = NULL;
		ft_do_pushswap(&stack_a, &stack_b, ft_read_instructions());
		ft_check_result(stack_a, stack_b);
	}
	ft_free_exit(&stack_a, &stack_b, llong_array);
	return (0);
}
