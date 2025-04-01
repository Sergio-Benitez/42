/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:14:25 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/01 14:15:05 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_ph_routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	while (1/*funcion pa ver si han cascao*/)
	{
	//	ft_ph_eat(philo);
	//	ft_ph_sleep(philo);
	//	ft_ph_fuck(philo);

	}
	return (NULL);
}
