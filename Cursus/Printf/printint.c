/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:12:00 by sbenitez          #+#    #+#             */
/*   Updated: 2024/06/24 21:58:05 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printint(int n, int *count)
{
	if (n == -2147483648)
		printstr("-2147483648", count);
	else if (n < 0)
	{
		printchar('-', count);
		printint(-n, count);
	}
	else if (n >= 10)
	{
		printint(n / 10, count);
		printchar(n % 10 + '0', count);
	}
	else
		printchar(n + '0', count);
}