/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:52:43 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/03 19:05:54 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	*table;
	long	*args;
	int		i;

	i = -1;
	if (ac == 5 || ac == 6)
	{
		args = ft_parse_args(ac, av, i);
		if (!args)
			return (1);
		if (args[0] == 0)
			if (ft_exit_error("Philo number must be more than '0'", args))
				return (1);
		table = safe_malloc(sizeof(t_table));
		if (!table || !ft_data_init(table, args, i))
			return (free(args), 1);
		free(args);
		ft_dinner_start(table);
		ft_clean(table);
	}
	else
		if (ft_exit_error("Invalid argument number.", NULL))
			return (1);
	return (0);
}
