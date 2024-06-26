/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:10:26 by sbenitez          #+#    #+#             */
/*   Updated: 2024/06/26 15:31:14 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printptr(void *ptr, int *count)
{
	unsigned long int	n;
	const char*			base;
	
	n = (unsigned long int)ptr;
	base = "0123456789abcdef";
	if (n >= 16)
		printptr((void *)(n / 16), count);
	printchar(base[n % 16], count);
}
