/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:16:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/28 13:42:13 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	seen(char *str, char c, int max)
{
	int	i = 0;
	while (i < max)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i = 0;
	int j;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!seen(argv[1], argv[1][i], i))
			{
				j = 0;
				while (argv[2][j])
				{
					if (argv[1][i] == argv[2][j])
					{
						write(1, &argv[1][i], 1);
						break;
					}
				j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}