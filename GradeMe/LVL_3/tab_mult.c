/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:29:11 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/22 20:58:08 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char digit;
	
	if (n > 9)
		putnbr(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	int	n = 0;
	int	i = 0;
	
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		n = n * 10 + (argv[1][i] - '0');
		i++;
	}
	i = 1;
	while (i < 10)
	{
		putnbr(i);
		write(1, " x ", 3);
		putnbr(n);
		write(1, " = ", 3);
		putnbr(n * i);
		write(1, "\n", 1);
		i++;	
	}
	return (0);
}