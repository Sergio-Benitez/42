/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:49:27 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/10 14:22:54 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != '\0') && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char			sauce[] = "Machacasaurio";
	char			desastre[] = "Amocafre";
	char			desastre2[] = "Amocafre";
	unsigned int	size = sizeof(desastre);

	unsigned int len1 = ft_strlcpy(desastre, sauce, size);
    printf("Cadena copiada por ft_strlcpy: %s, Longitud: %u\n", desastre, len1);
	unsigned int len2 = strlcpy(desastre2, sauce, size);
    printf("Cadena copiada por strlcpy: %s, Longitud: %u\n", desastre2, len2);

	return (0);
}
*/
