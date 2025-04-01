/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:52:43 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/01 19:45:07 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	*table;
	long	*args;

	if (ac == 5 || ac == 6)
	{
		args = ft_parse_args(ac, av);
		if (args[0] == 0)
		{
			free(args);
			ft_exit_error("Philo number must be more than '0'");
		}
		table = safe_malloc(sizeof(t_table));
		ft_data_init(table, args);
		free(args);
		ft_dinner_start(table);
		ft_clean(table);
	}
	else
		ft_exit_error("Invalid argument number.");
	return (0);
}
