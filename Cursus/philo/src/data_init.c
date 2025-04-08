/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:17:08 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/03 19:49:34 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	assign_forks(t_philo *philo, t_fork *forks, int philo_pos)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	if (philo->id == 1)
	{
		philo->left_fork = &forks[(philo_pos)];
		philo->right_fork = &forks[philo_nbr -1];
	}
	else
	{
		philo->left_fork = &forks[(philo_pos)];
		philo->right_fork = &forks[philo_pos - 1];
	}
}

void	ft_philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->thread_id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		philo->last_meal = ft_get_time();
		assign_forks(philo, table->forks, i);
	}
}

void	*ft_data_init(t_table *table, long *args, int i)
{
	table->philo_nbr = args[0];
	table->time_to_die = args[1];
	table->time_to_eat = args[2];
	table->time_to_sleep = args[3];
	if (args[4] >= 0)
		table->nbr_limit_meals = args[4];
	else
		table->nbr_limit_meals = -1;
	table->end_simulation = false;
	table->start_simulation = ft_get_time();
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	if (!table->philos || !table->forks)
		return (NULL);
	while (++i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i].fork, NULL);
		table->forks[i].fork_id = i;
	}
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->eat_lock, NULL);
	ft_philo_init(table);
	return ("xd");
}
