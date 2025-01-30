/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:10:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:24:24 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	check_param(char f, va_list *ap, int *i, int *count)
{
	if (f == '%')
		printchar('%', count);
	else if (f == 'c')
		printchar(va_arg(*ap, int), count);
	else if (f == 's')
		printstr(va_arg(*ap, char *), count);
	else if (f == 'p')
		check_ptr(va_arg(*ap, void *), count);
	else if (f == 'd' || f == 'i')
		printint(va_arg(*ap, int), count);
	else if (f == 'u')
		printuns(va_arg(*ap, unsigned int), count);
	else if (f == 'x' || f == 'X')
		printhex(va_arg(*ap, unsigned int), f, count);
	else
		(*i)--;
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_param(format[i], &ap, &i, &count);
			i++;
		}
		else
			printchar(format[i++], &count);
	}
	va_end(ap);
	return (count);
}
