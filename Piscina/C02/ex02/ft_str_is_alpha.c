/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:15:32 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/06 13:32:21 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
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
			if (((str[i] < 65) || (str[i] > 90))
				&& ((str[i] < 97) || (str[i] > 122)))
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
	int		retrn = ft_str_is_alpha(str);
	if (retrn == 1)
	{
		write(1, "1", 1);
	}
	else
	{
		write(1, "0", 1);
	}
}*/
