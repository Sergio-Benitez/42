/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:45:03 by labderra          #+#    #+#             */
/*   Updated: 2024/03/21 14:08:08 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

char	*ft_strtrim(char *src, int nb)
{
	int	i;

	i = 0;
	while (src[nb + i] != '\0')
	{
		src[i] = src[nb + i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

char	*ft_strclip(char *dest, char *src, int nb)
{
	int	i;

	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_atoi(char *str)
{
	int	acc;
	int	sign;

	sign = 1;
	acc = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		acc = acc * 10 + *str - 48;
		str++;
	}
	return (sign * acc);
}
