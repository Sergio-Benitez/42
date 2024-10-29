/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:10:34 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/29 15:24:42 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	printstr(char *str, int *count)
{
	if (!str)
		return (printstr("(null)", count));
	while (*str)
	{
		*count += write(1, str++, 1);
	}
}
