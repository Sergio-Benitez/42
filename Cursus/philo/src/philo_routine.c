/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:14:25 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/03 17:07:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_think(t_philo *philo)
{
	if (ft_check_alive(philo))
		ft_print_action("is thinking", philo, BLUE);
	ft_usleep(1);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_check_alive(philo))
		ft_print_action("is sleeping", philo, GREEN);
	ft_usleep(philo->table->time_to_sleep);
}

void	ft_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		if (ft_check_alive(philo))
			ft_print_action("has taken a fork", philo, ORANGE);
		pthread_mutex_lock(&philo->left_fork->fork);
		if (ft_check_alive(philo))
			ft_print_action("has taken a fork", philo, ORANGE);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		if (ft_check_alive(philo))
			ft_print_action("has taken a fork", philo, ORANGE);
		pthread_mutex_lock(&philo->right_fork->fork);
		if (ft_check_alive(philo))
			ft_print_action("has taken a fork", philo, ORANGE);
	}
}

void	ft_eat(t_philo *philo)
{
	if (philo->table->philo_nbr == 1)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		if (ft_check_alive(philo))
			ft_print_action("has taken a fork", philo, ORANGE);
		ft_usleep(philo->table->time_to_eat);
		pthread_mutex_unlock(&philo->left_fork->fork);
		return ;
	}
	ft_take_forks(philo);
	if (ft_check_alive(philo))
		ft_print_action("is eating", philo, WHITE);
	pthread_mutex_lock(&philo->table->eat_lock);
	philo->last_meal = ft_get_time();
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->table->eat_lock);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	*ft_ph_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (ft_check_alive(philo))
	{
		if (ft_check_alive(philo))
			ft_eat(philo);
		if (ft_check_alive(philo))
			ft_sleep(philo);
		if (ft_check_alive(philo))
			ft_think(philo);
	}
	return (args);
}
