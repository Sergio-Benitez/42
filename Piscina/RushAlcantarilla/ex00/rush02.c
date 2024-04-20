/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:56:13 by mhoyuela          #+#    #+#             */
/*   Updated: 2024/03/17 20:32:33 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printnumberinwords2(char *number)
{
	int	i;

	i = 0;
	while (number[i] != '\0')
		i++;
	if (i == 1)
	{
		if (*number == '5')
			write(1, "Five", 4);
		else if (*number == '6')
			write(1, "Six", 3);
		else if (*number == '7')
			write(1, "Seven", 5);
		else if (*number == '8')
			write(1, "Eight", 5);
		else if (*number == '9')
			write(1, "Nine", 4);
	}
	else if (i > 1)
		write(1, "Number too big, bro.", 20);
}

void	printnumberinwords(char *number)
{
	int	i;

	i = 0;
	while (number[i] != '\0')
		i++;
	if (i == 1)
	{
		if (*number == '0')
			write(1, "Zero", 4);
		else if (*number == '1')
			write(1, "One", 3);
		else if (*number == '2')
			write(1, "Two", 3);
		else if (*number == '3')
			write(1, "Three", 5);
		else if (*number == '4')
			write(1, "Four", 4);
	}
	else if (i > 1)
		write(1, "Number too big, bro.", 20);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (argv[1][0] >= '0' && argv[1][0] <= '4')
			printnumberinwords(&argv[1][0]);
		else if (argv[1][0] >= '5')
			printnumberinwords2(&argv[1][0]);
	}
	else
		write(2, "Error: \nNot a valid argument.", 30);
	return (0);
}
//featuring La Espe, and thanks to the moral support of El David Amarillo
