/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:23:25 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/01 19:45:56 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_dinner_start(t_table *table)
{
	pthread_t	monitor;
	int			i;

	i = -1;
	if (pthread_create(&monitor, NULL, &ft_mt_routine, table) != 0)
		return ;
	while (++i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				&ft_ph_routine, &table->philos[i]))
			return ;
	}
	if (pthread_join(monitor, NULL) != 0)
		return ;
	while (++i < table->philo_nbr)
	{
		if (pthread_join(table->philos[i].thread_id, NULL) != 0)
			return ;
	}
}
