/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:48:08 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/03 20:37:44 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int res = 0;
	
	while (*s)
		res = res *10 + *s++ - '0';
	return (res);
}

int	is_prime(int num)
{
	int i = 2;
	
	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}

	return (1);
}

void	putnbr(int n)
{
	if (n > 9)
		putnbr(n / 10);
	char digit =  n % 10 + '0';
	write(1, &digit, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int nbr = ft_atoi(argv[1]);
		int sum = 0;

		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		putnbr(sum);
	}
	if (argc != 2)
		putnbr(0);
	write(1, "\n", 1);
	return (0);
}