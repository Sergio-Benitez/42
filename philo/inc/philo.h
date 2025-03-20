/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:02:21 by sbenitez          #+#    #+#             */
/*   Updated: 2025/03/20 17:23:41 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef pthread_mutex_t t_mtx;
typedef struct	s_table t_table;

typedef struct	s_fork
{
	t_mtx	fork;
	int		fork_id;
}				t_fork;


typedef struct	s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

typedef struct	s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	int		is_anyone_dead;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}				t_table;


// DATA_INIT.C

void	ft_data_init(t_table *table, long *args);

// MAIN.C

// SAFE_FUNCTIONS.C

void	*safe_malloc(size_t bytes);

// UTILS.C

void	ft_exit_error(char *str);
long	ft_atol(const char *str);
int		ft_check_int(char **av);
long	*ft_parse_args(int ac, char **av);
void	ft_usleep(int usec);
long	ft_get_time();
int	ft_is_everyone_alive(t_table *table);
int	ft_everyone_eated(t_table *table);
void	*ft_mt_routine(void	*args);

#endif