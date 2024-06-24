/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/06/24 17:00:05 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int	i;
	int	count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while(format[i])
	{
		if(format[i] != '%')		
			printchar(format[i++]);
		else
			if(format[i+1] == 'c')
			{
				i += 2;
				printchar(va_arg(ap, int));
			}
			if(format[i+1] == 's')
			{
				i += 2;
				printstr(va_arg(ap, char *));
			}
			if(format[i+1] == 'p')
			if(format[i+1] == 'd')
			if(format[i+1] == 'i')
			if(format[i+1] == 'u')
			if(format[i+1] == 'x')
			if(format[i+1] == 'X')
			if(format[i+1] == '%')
;	}
	///
	va_end(ap);
	return (i);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("Me como una tremenda %s de locos\n", "verga");
	printf("Me como una tremenda %s de locos\n", "verga");
	return (0);
}