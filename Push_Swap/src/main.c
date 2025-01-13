/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:40:46 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/13 14:18:14 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 1;
	if (argc < 2) // no params = return control
		return (0);
	if (ft_check_numbers(argv)); // Error\n = check_enteros, check_><entero, check_duplicados
	{
		stack_a = ft_newstack();
	}
	while (argv[i])
	{
		//ft_lstnew()
		i++;
	}
	
	return (0);
}