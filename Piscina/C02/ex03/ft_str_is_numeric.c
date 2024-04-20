/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:15:32 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/06 12:21:17 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
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
			if ((str[i] < 48) || (str[i] > 57))
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
	char	str[] = "Macarr0nes";
	int		retrn = ft_str_is_numeric(str);

	ft_str_is_numeric(str);
	if (retrn == 1)
	{
		write(1, "1", 1);
	}
	else
	{
		write(1, "0", 1);
	}
}*/
