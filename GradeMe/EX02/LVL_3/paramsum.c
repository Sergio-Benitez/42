/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:46:50 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/28 20:52:04 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int num)
{
	char digit;
	if (num > 9)
		putnbr(num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

int main(int argc, char **argv)
{
	putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}