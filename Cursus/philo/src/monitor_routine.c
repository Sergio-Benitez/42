/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:21:14 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/03 20:03:25 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_check_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_lock);
	if (philo->table->end_simulation)
	{
		pthread_mutex_unlock(&philo->table->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (1);
}

int	ft_anyone_died(t_table *table)
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
			return (1);
		}
	}
	pthread_mutex_unlock(&table->eat_lock);
	return (0);
}

int	ft_everyone_eaten(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->eat_lock);
		if (table->philos[i].meals_counter < table->nbr_limit_meals)
		{
			pthread_mutex_unlock(&table->eat_lock);
			return (0);
		}
		pthread_mutex_unlock(&table->eat_lock);
	}
	return (1);
}

void	*ft_mt_routine(void	*args)
{
	t_table	*table;

	table = (t_table *)args;
	while (1)
	{
		pthread_mutex_lock(&table->dead_lock);
		if ((table->nbr_limit_meals > 0 && ft_everyone_eaten(table))
			|| ft_anyone_died(table))
			table->end_simulation = true;
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&table->dead_lock);
	}
	return (args);
}
