/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:04:10 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/01 19:47:57 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_destroy_mutex(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
		pthread_mutex_destroy(&table->forks[i].fork);
	pthread_mutex_destroy(&table->eat_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->dead_lock);
}

void	ft_clean(t_table *table)
{
	free(table->philos);
	free(table->forks);
	ft_destroy_mutex(table);
	free(table);
}

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		ft_exit_error("Error with the malloc");
	return (ret);
}

long	ft_get_time(void)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, NULL);
	ret = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ret);
}

void	ft_usleep(int usec)
{
	if (usleep(usec * 1000) == -1)
		return ;
}
