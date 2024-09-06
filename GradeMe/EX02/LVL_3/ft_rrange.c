/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:40:08 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/21 16:08:49 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	count;
	int *array;

	i = 0;
	if (start <= end)
        count = end - start + 1;
    else
        count = start - end + 1;
	array = (int *)malloc(count * sizeof(int));
	if (!array)
		return (NULL);
	if (start <= end)
	{
		while (i < count)
		{
			array[i] = end - i;
			i++;
		}
	}
	else
	{
		while (i < count)
		{
			array[i] =  end + i;
			i++;
		}
	}
	return (array);
}
