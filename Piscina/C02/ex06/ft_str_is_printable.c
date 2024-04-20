/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:15:32 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/06 14:18:43 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
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
			if ((str[i] > 126) || (str[i] < 32))
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
	int		retrn = ft_str_is_printable(str);

	if (retrn == 1)
	{
		write(1, "1", 1);
	}
	else
	{
		write(1, "0", 1);
	}
}*/
