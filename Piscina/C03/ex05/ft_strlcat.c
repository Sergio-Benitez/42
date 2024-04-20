/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:19:22 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/11 16:32:05 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	a;

	i = 0;
	j = 0;
	a = 0;
	while (dest[i] != '\0')
		i++;
	while (src[a] != '\0')
		a++;
	if (size <= i)
		a = a + size;
	else
		a = a + i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (a);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "ni idea.";
	char	dest[] = "No tengo ";

	printf ("%u", ft_strlcat(dest, src, 8));
	return (0);
}*/
