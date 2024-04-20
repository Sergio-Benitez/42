/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:56:14 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/04 16:26:07 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*#include <stdio.h>

int	main(void)
{
	int	div;
	int	mod;
	ft_div_mod(10, 5, &div, &mod);
	printf ("div: %d, mod: %d", div, mod);
	return (0);
}*/
