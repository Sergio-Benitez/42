/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:02:21 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/03 19:37:38 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RST "\033[0m"	// 
# define BLUE "\033[0;96m"		// THINK
# define GREEN "\033[0;32m"		// SLEEP
# define ORANGE "\033[0;33m"	// TAKE FORK
# define RED "\033[0;31m"		// DIED
# define WHITE "\033[37;1m"		// EAT

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	t_philo	*philos;
	t_fork	*forks;
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	t_mtx	print_lock;
	t_mtx	eat_lock;
	t_mtx	dead_lock;
}				t_table;

// DATA_INIT.C

void	assign_forks(t_philo *philo, t_fork *forks, int philo_pos);
void	ft_philo_init(t_table *table);
void	*ft_data_init(t_table *table, long *args, int i);

// DINNER_START.C

void	ft_dinner_start(t_table *table);

// MAIN.C

// MONITOR_ROUTINE.C

int		ft_check_alive(t_philo *philo);
int		ft_anyone_died(t_table *table);
int		ft_everyone_eaten(t_table *table);
void	*ft_mt_routine(void	*args);

// PHILO_ROUTINE.C

void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_take_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	*ft_ph_routine(void *args);

// UTILS.C

int		ft_exit_error(char *str, long *args);
long	ft_atol(const char *str);
int		ft_check_int(char **av);
long	*ft_parse_args(int ac, char **av, int i);
void	ft_print_action(char *str, t_philo *philo, char *color);

// UTILS2.C

void	ft_clean(t_table *table);
void	*safe_malloc(size_t bytes);
void	ft_usleep(int usec);
long	ft_get_time(void);
void	ft_destroy_mutex(t_table *table);

#endif