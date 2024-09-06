/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:38:06 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/28 20:01:25 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
	int *array;
	int i = 0;
	int len = end - start + 1;

	if (len < 0)
		len = -len;
		
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	if (start == end)
		array[i] = start;
	if (start < end)
	{
		while (start <= end)
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	else if (end < start)
	{
		while (end <= start)
		{
			array[i] = start;
			start--;
			i++;
		}
	}
	return (array);
}