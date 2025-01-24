/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:57:42 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/24 12:42:35 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**ft_clean_quote(char **argv)
{
	int		i;
	char	*arg_str;
	char	*temp;
	char	**clean_args;

	i = 1;
	arg_str = "";
	while (argv[i])
	{
		temp = arg_str;
		arg_str = ft_strjoin(arg_str, argv[i]);
		if (i > 1)
			free(temp);
		temp = arg_str;
		arg_str = ft_strjoin(arg_str, " ");
		free(temp);
		i++;
	}
	clean_args = ft_split(arg_str, ' ');
	free(arg_str);
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
		if (clean_args[i][j] == '+' || clean_args[i][j] == '-')
			j++;
		if (clean_args[i][j] == '\0')
			return (0);
		while (clean_args[i][j])
		{
			if (!(clean_args[i][j] >= '0' && clean_args[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_limits(long long *llong_array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (llong_array[i] > INT_MAX || llong_array[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_dups(long long *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	*ft_check_args(char **argv, int *size)
{
	char		**clean_args;
	long long	*llong_array;

	clean_args = ft_clean_quote(argv);
	if (!clean_args || !clean_args[0])
		return (ft_putendl_fd("Error", 2), NULL);
	if (!ft_check_int(clean_args))
		return (ft_putendl_fd("Error", 2), NULL);
	while (clean_args[*size])
		(*size)++;
	llong_array = ft_llongize_args(clean_args, *size);
	ft_free_matrix(clean_args);
	if (!llong_array)
		return (ft_putendl_fd("Error", 2), NULL);
	if (!ft_check_limits(llong_array, *size))
		return (ft_putendl_fd("Error", 2), NULL);
	if (!ft_check_dups(llong_array, *size))
		return (ft_putendl_fd("Error", 2), NULL);
	return (llong_array);
}
