/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:11:19 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/04 21:15:22 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size -1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}
/*#include <stdio.h>

int	main(void)
{
	int	arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft_rev_int_tab(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
	return (0);
}*/
