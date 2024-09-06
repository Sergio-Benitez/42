/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:30:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/21 15:58:22 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*aux;

	i = 0;
	while (src[i])
		i++;
	aux = malloc(i + 1 * sizeof(char));
	i = 0;
	while (src[i])
	{
		aux[i] = src[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}