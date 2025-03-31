/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:23:25 by sbenitez          #+#    #+#             */
/*   Updated: 2025/03/31 21:17:56 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* void	ft_ph_eat(t_philo *philo)
{
	
} */

void	*ft_ph_routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	while (1)
	{
	//	ft_ph_eat(philo);
	//	ft_ph_sleep(philo);
	//	ft_ph_fuck(philo);
		//mutex
		if (philo->table->end_simulation)
		{
			//dsmutex	
			break ;
		}
		//desmutex
	}
	return (NULL);
}

void	ft_dinner_start(t_table *table)
{
	pthread_t	monitor;
	int			i;
	
	i = -1;
	if (pthread_create(&monitor, NULL, &ft_mt_routine, table) != 0)
		return ;//fallo del create. protecsiao
	while (++i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL, &ft_ph_routine, &table->philos[i]))
			return ;//fallo de creacion
	}
	if (pthread_join(monitor, NULL) != 0)
		return ;//destroy??
	while (++i < table->philo_nbr)
	{
		if (pthread_join(table->philos[i].thread_id, NULL) != 0)
			return ;//destroy???
	}
}