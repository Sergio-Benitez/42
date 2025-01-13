/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:57:42 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/13 19:41:50 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**ft_clean_args(char **argv)
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

int	ft_check_args(char **argv, t_node **stack_a)
{
	int		i = 0;
	char	**clean_args;

	clean_args = ft_clean_args(argv);
	if (!clean_args)
		return (ft_putendl_fd("Error\nInvalid arguments.\n", 2), 0);
	while (clean_args[i])
	{
		ft_printf("limpio: %s\n", clean_args[i]);
		i++;
	}
	while (--i > -1)
		ft_pushnode(stack_a, ft_atoi(clean_args[i]));
/* 	if (!ft_check_int(clean_args))
		return (ft_putendl_fd("Error\nArguments must be integers.\n", 2), 0);
	if (!ft_check_limits(clean_args))
		return (ft_putendl_fd("Error\nArguments out of int range.\n", 2), 0);
	if (!ft_check_duplicates(clean_args))
		return (ft_putendl_fd("Error\nDuplicate arguments found.\n", 2), 0); */
    return (1);
}
