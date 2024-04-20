/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:05:27 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/12 14:53:49 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Buscame esta, crack";
	char	to_find[] = "esta";
	char	*result = ft_strstr(str, to_find);

	if (result != 0)
		printf ("Subcadena '%s' encontrada", to_find);
	else
		printf ("Subcadena '%s' no encontrada", to_find);
	return (0);
}*/
