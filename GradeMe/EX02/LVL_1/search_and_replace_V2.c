/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:59:53 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/21 13:12:41 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sar(char *str, char a, char b)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4 || argv[2][1] || argv[3][1])
	{
		write(1, "\n", 1);
		return (1);
	}
	sar(argv[1], *argv[2], *argv[3]);
	write(1, "\n", 1);
	return (0);
}