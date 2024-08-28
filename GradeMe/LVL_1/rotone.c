/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:19:28 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/28 12:26:59 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				if (argv[1][i] == 'z')
					argv[1][i] = 'a';
				else
					argv[1][i] += 1;
			}
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				if (argv[1][i] == 'Z')
					argv[1][i] = 'A';
				else
					argv[1][i] += 1;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}