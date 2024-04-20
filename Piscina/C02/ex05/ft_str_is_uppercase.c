/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:15:32 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/06 14:07:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	else
	{
		while (str[i] != '\0')
		{
			if ((str[i] > 90) || (str[i] < 65))
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
}
/*#include <unistd.h>

int	main(void)
{
	char	str[] = "Maracas";
	int		retrn = ft_str_is_uppercase(str);

	if (retrn == 1)
	{
		write(1, "1", 1);
	}
	else
	{
		write(1, "0", 1);
	}
}*/
