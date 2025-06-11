/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:10:26 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:24:39 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	printptr(void *ptr, int *count)
{
	unsigned long int	n;
	const char			*base;

	n = (unsigned long int)ptr;
	base = "0123456789abcdef";
	if (n >= 16)
		printptr((void *)(n / 16), count);
	printchar(base[n % 16], count);
}

void	check_ptr(void *ptr, int *count)
{
	if (ptr == 0)
	{
		printstr("(nil)", count);
		return ;
	}
	*count += write(1, "0x", 2);
	printptr(ptr, count);
}
