/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:49:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/05 11:35:48 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
/*#include <stdio.h>

int main(void)
{
    int arr[10] = {9, 1, 0, 7, 4, 2, 6, 3, 8, 5};
    ft_sort_int_tab(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
    return (0);
}*/
