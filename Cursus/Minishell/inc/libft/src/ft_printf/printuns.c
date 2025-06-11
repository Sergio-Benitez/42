/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:10:51 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:24:45 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	printuns(unsigned int n, int *count)
{
	if (n >= 10)
	{
		printint(n / 10, count);
		printchar(n % 10 + '0', count);
	}
	else
		printchar(n + '0', count);
}
