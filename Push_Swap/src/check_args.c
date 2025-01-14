/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:57:42 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/14 14:38:00 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**ft_clean_quote(char **argv)
{
	int		i;
	char	*arg_str;
	char	**clean_args;

	i = 1;
	arg_str = "";
	while (argv[i])
	{
		arg_str = ft_strjoin(arg_str, argv[i]);
		arg_str = ft_strjoin(arg_str, " ");
		i++;
	}
	clean_args = ft_split(arg_str, ' ');
	return (clean_args);
}

int	ft_check_int(char **clean_args)
{
	int	i;
	int	j;

	i = 0;
	while (clean_args[i])
	{
		j = 0;
		while (clean_args[i][j])
		{
			if (!((clean_args[i][j] >= '0' && clean_args[i][j] <= '9')
				|| clean_args[i][j] == '+' || clean_args[i][j] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_limits(long long *llong_array)
{
 	int	i;

	i = 0;
	while (llong_array[i])
	{
		if (llong_array[i] > INT_MAX || llong_array[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(char **argv, t_node **stack_a)
{
	char		**clean_args;
	long long	*llong_array;

	clean_args = ft_clean_quote(argv);
	if (!clean_args)
		return (ft_putendl_fd("Error\nInvalid arguments.\n", 2), 0);
 	if (!ft_check_int(clean_args))
		return (ft_putendl_fd("Error\nArguments must be integers.\n", 2), 0);	
	llong_array = ft_llongize_args(clean_args);
	if (!ft_check_limits(llong_array))
		return (ft_putendl_fd("Error\nArguments out of int range.\n", 2), 0);

/*	if (!ft_check_duplicates(clean_args))
		return (ft_putendl_fd("Error\nDuplicate arguments found.\n", 2), 0); */

 	int	i = 0;
	while (clean_args[i])				// PRINT ARGS
	{
		ft_printf("limpio: %s\n", clean_args[i]);
		i++;
	}
	while (--i > -1)					// CREAR STACK A
		ft_pushnode(stack_a, (int)llong_array[i]);
		
	return (1);
}
