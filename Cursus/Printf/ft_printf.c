/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/06/24 22:23:44 by sbenitez         ###   ########.fr       */
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
//			else if(format[i+1] == 'p')
			else if(format[i+1] == 'd' || format[i+1] == 'i')
			{
				i += 2;
				printint(va_arg(ap, int), &count);
			}
//			else if(format[i+1] == 'u')
//			else if(format[i+1] == 'x' || format[i+1] == 'X')
;	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	ft_printf(" || Count = %d\n", ft_printf("FT_PRINTF: %%c = %c, %%s = %s, %%d = %d, %%i = %i", 'c', "loco", -3, 5));
	printf(" || Count = %d\n", printf("   PRINTF: %%c = %c, %%s = %s, %%d = %d, %%i = %i", 'c', "loco", -3, 5));
	return (0);
}