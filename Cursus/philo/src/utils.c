/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:01:54 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/03 19:12:24 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_exit_error(char *error, long *args)
{
	if (args != NULL)
		free(args);
	printf("%s\n", error);
	return (1);
}

long	ft_atol(const char *str)
{
	long	result;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			if (ft_exit_error("Arguments can't be negative.", NULL))
				return (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (LONG_MAX);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	ft_check_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	*ft_parse_args(int ac, char **av, int i)
{
	long	*args;

	if (!ft_check_int(av))
		if (ft_exit_error("Arguments must be integers.", NULL))
			return (NULL);
	args = safe_malloc(sizeof(long) * (ac));
	if (!args)
		return (NULL);
	while (++i < ac - 1)
	{
		args[i] = ft_atol(av[i + 1]);
		if (args[i] < 0)
			return (free(args), NULL);
		if (args[i] < INT_MIN || args[i] > INT_MAX)
		{
			if (ft_exit_error("Args must fit within integer limits.", args))
				return (NULL);
		}
		else if (i > 0 && i < 4 && args[i] < 60)
			if (ft_exit_error("Use timestamps major than 60ms.", args))
				return (NULL);
	}
	args[i] = -1;
	return (args);
}

void	ft_print_action(char *str, t_philo *philo, char *color)
{
	long	time;

	pthread_mutex_lock(&philo->table->print_lock);
	time = ft_get_time() - philo->table->start_simulation;
	printf("%s[%ld] %d %s%s\n", color, time, philo->id, str, RST);
	pthread_mutex_unlock(&philo->table->print_lock);
}
