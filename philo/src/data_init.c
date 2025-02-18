/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:17:08 by sbenitez          #+#    #+#             */
/*   Updated: 2025/02/18 17:30:28 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_data_init(t_table *table, long *args)
{
	table->philo_nbr = args[0];
	table->time_to_die = args[1] * 1000;
	table->time_to_eat = args[2] * 1000;
	table->time_to_sleep = args[3] * 1000;
	if (args[4] != -1)
		table->nbr_limit_meals = args[4];
	else
		table->nbr_limit_meals = -1;
	table->end_simulation = false;
	table->philos = safe_malloc(table->philo_nbr);
}
