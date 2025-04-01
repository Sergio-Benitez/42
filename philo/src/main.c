/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:52:43 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/01 14:13:06 by sbenitez         ###   ########.fr       */
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
