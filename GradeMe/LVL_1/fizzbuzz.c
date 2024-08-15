/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:11:18 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/25 13:25:16 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fizzbuzz(void)
{
	int	i;

	i = 1;
	while (i < 101)
	{
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
				write(1, "fizzbuzz\n", 9);
			else
				write(1, "fizz\n", 5);
		}
		else if (i % 5 == 0)
		{
			if (i % 3 == 0)
				write(1, "fizzbuzz\n", 9);
			else
				write(1, "buzz\n", 5);
		}
		else
		{
			write(1, &i, 1);
			write(1, "\n", 1);
		}
		i++;
	}
}

int	main(void)
{
	fizzbuzz();
	return (0);
}