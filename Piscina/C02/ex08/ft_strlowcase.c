/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:47:27 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/06 16:30:02 by sbenitez         ###   ########.fr       */
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
/*#include <stdio.h>

int	main()
{
	char	strg[] = "PANDERETAS";
	printf("%s", ft_strlowcase(strg));
	return (0);
}*/
