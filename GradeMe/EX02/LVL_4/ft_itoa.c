/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:58:06 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/05 12:18:29 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char *ascii;
	int n = nbr;
	int len = 0;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	if (nbr <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	ascii = (char *)malloc((len + 1) * sizeof(char));
	if (!ascii)
		return (NULL);
	ascii[len] = '\0';
	if (nbr == 0)
	{
		ascii[0] = '0';
		return (ascii);
	}
	if (nbr < 0)
	{
		ascii[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		ascii[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ascii);
}