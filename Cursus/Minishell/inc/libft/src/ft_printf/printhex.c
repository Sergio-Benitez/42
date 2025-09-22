/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:10:08 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:24:29 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	printhex(unsigned int n, const char x, int *count)
{
	const char	*base;

	if (x == 'x')
	{
		base = "0123456789abcdef";
		if (n >= 16)
			printhex(n / 16, 'x', count);
		printchar(base[n % 16], count);
	}
	if (x == 'X')
	{
		base = "0123456789ABCDEF";
		if (n >= 16)
			printhex(n / 16, 'X', count);
		printchar(base[n % 16], count);
	}
}
