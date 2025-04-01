/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:21:14 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/01 14:27:36 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int		ft_anyone_died(t_table *table)
{
	int		i;
	long	aux;

	i = -1;
	pthread_mutex_lock(&table->eat_lock);
	while (++i < table->philo_nbr)
	{
		aux = ft_get_time() - table->philos[i].last_meal;
		if (aux >= table->time_to_die)
		{
			ft_print_action("died", &table->philos[i], RED);
			pthread_mutex_unlock(&table->eat_lock);
			return (0);
		}
	}
	pthread_mutex_unlock(&table->eat_lock);
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
		if ((table->nbr_limit_meals > 0 && ft_everyone_eated(table))
			|| ft_anyone_died(table))
			table->end_simulation = true;//mutex 
		if (table->end_simulation)//NULL al detectar esta flag
			break ;
	}
	return (NULL);
}