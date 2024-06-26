/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/06/26 16:58:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>    // BORRAR BORRAR BORRAR

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
			printchar(format[i++], &count);
		else
			if(format[i+1] == '%')
			{
				i += 2;
				printchar('%', &count);
			}
			else if(format[i+1] == 'c')
			{
				i += 2;
				printchar(va_arg(ap, int), &count);
			}
			else if(format[i+1] == 's')
			{
				i += 2;
				printstr(va_arg(ap, char *), &count);
			}
			else if(format[i+1] == 'p')
			{
				i += 2;
				count += write(1, "0x", 2);
				printptr(va_arg(ap, void *), &count);
			}
			else if(format[i+1] == 'd' || format[i+1] == 'i')
			{
				i += 2;
				printint(va_arg(ap, int), &count);
			}
			else if(format[i+1] == 'u')
			{
				i += 2;
				printuns(va_arg(ap, unsigned int), &count);
			}
			else if(format[i+1] == 'x' || format[i+1] == 'X')
			{
				i += 2;
				printhex(va_arg(ap, unsigned int), format[i-1], &count);
			}
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	 int	x;
	
	x = 98988989;
	ft_printf(" || Count = %d\n", ft_printf("FT_PRINTF: %%c = %c, %%s = %s, %%d = %d, %%i = %i, %%u = %u, %%p = %p, %%x = %x, %%X = %X", 'c', "loco", -3, 5, 32, (void *)&x, x, x));
	printf(" || Count = %d\n", printf("   PRINTF: %%c = %c, %%s = %s, %%d = %d, %%i = %i, %%u = %u, %%p = %p, %%x = %x, %%X = %X", 'c', "loco", -3, 5, 32, (void *)&x, x, x));
	return (0);
}