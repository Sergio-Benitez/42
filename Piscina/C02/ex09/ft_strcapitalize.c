/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:54:28 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/10 19:28:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 64) && (str[i] < 91))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if ((str[i] > 96) && (str[i] < 123))
				str[i] = str[i] - 32;
		}
		else
		{
			if (((str[i - 1] < 65) || (str[i - 1] > 90))
				&& ((str[i - 1] < 97) || (str[i - 1] > 122))
				&& ((str[i - 1] < 48) || (str[i - 1] > 57))
				&& (str [i] > 96) && (str[i] < 123))
			{
				str [i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char strg[] = "salut, coMMent tu vas ? 42mots quarante-deux";
	printf("%s", ft_strcapitalize(strg));
	return (0);
}
*/
