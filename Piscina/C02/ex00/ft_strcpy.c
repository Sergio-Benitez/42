/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:40:17 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/08 10:16:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*#include <stdio.h>

int	main(void)
{
	char	strsrc[12] = "Macarrones";
	char	strdest[12];

	ft_strcpy(strdest, strsrc);
	printf("Dest: %s", strdest);
	return (0);
}*/
