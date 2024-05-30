/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/05/30 22:58:59 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while(format[i])
	{
		if(format[i] != '%')		
			printchar(format[i++]);
		else
			if(format[i+1] == 'c')
				printchar(format[++i]);
			if(format[i+1] == 's')
//				printstr();
			if(format[i+1] == 'p')
			if(format[i+1] == 'd')
			if(format[i+1] == 'i')
			if(format[i+1] == 'u')
			if(format[i+1] == 'x')
			if(format[i+1] == 'X')
			if(format[i+1] == '%')
;
	}
	///
	va_end(args);
	return (i);
}

int	main(void)
{
	ft_printf("Me como una tremenda %c", "verga");
	return (0);
}