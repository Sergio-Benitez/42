/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:50:25 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/01 19:50:26 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int	x;

	x = 98988989;
	ft_printf(" || Count = %d\n", ft_printf("FT_PRINTF: %%c = %c, %%s = %s, %%d = %d, %%i = %i, %%u = %u, %%p = %p, %%x = %x, %%X = %X", 'c', "loco", -3, 5, 32, (void *)&x, x, x));
	printf(" || Count = %d\n", printf("   PRINTF: %%c = %c, %%s = %s, %%d = %d, %%i = %i, %%u = %u, %%p = %p, %%x = %x, %%X = %X", 'c', "loco", -3, 5, 32, (void *)&x, x, x));
	return (0);
}
