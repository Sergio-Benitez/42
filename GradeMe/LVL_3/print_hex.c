/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:28:23 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/04 18:53:28 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int num;
	
	while(*str)
	{
		num = (10 * num) + *str - '0';
		str++;
	}
	return (num);
}

void	print_hex(int n)
{
	char base[] = "0123456789abcdef";

	if (n > 16)
		print_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}