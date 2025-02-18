/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:52:43 by sbenitez          #+#    #+#             */
/*   Updated: 2025/02/17 16:29:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	*table;
	long	*args;
	
	table = NULL;
	if (ac == 5 || ac == 6)
	{
		args = ft_parse_args(ac, av);
		ft_data_init(table, args);
		free(args);
		printf("philo_nbr: %ld\ntime_to_die: %ld\ntime_to_eat: %ld\ntime_to_sleep: %ld\n", table->philo_nbr, table->time_to_die, table->time_to_eat, table->time_to_sleep);
		if (table->nbr_limit_meals < 0)
			printf("nbr_limit_meals: %ld\n", table->nbr_limit_meals);
//		dinner_start(&table);
//		clean(&table);
	}
	else
		ft_exit_error("Invalid argument number.");
	return (0);
}