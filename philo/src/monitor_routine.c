/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:21:14 by sbenitez          #+#    #+#             */
/*   Updated: 2025/03/20 17:21:34 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_is_everyone_alive(t_table *table)
{
	int		i;
	
	i = -1;
	while (++i < table->philo_nbr)
	{
		//mutex
		if (ft_get_time() - table->philos[i].last_meal_time >= table->philos[i].table->time_to_die)
		{
			//desmutex
			return (0);
		}
		//desmutex
	}
	return (1);
}

int	ft_everyone_eated(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		//mutex seguro
		if (table->philos[i].meals_counter < table->nbr_limit_meals)
		{
			//desmutex
			return (0);
		}
		//desmutex
	}
	return (1);
}

void	*ft_mt_routine(void	*args)
{
	t_table	*table;

	table = (t_table *)args;
	while (1)
	{
		if (ft_everyone_eated(table) || !ft_is_everyone_alive(table))
			table->end_simulation = 1;//mutex quiza no pq los filosofos devuelven 
		if (table->end_simulation)//NULL al detectar esta flag
			break ;
	}
	return (NULL);
}