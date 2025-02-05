/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:52:43 by sbenitez          #+#    #+#             */
/*   Updated: 2025/02/05 18:31:53 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	
	if (ac == 5 || ac == 6)
	{
		ft_parse_args(&table, ac, av);
		data_init(&table);
		dinner_start(&table);
		clean(&table);
	}
	else
		ft_exit_error("Invalid argument number.");
	return (0);
}