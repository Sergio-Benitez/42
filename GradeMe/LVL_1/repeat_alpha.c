/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:55:14 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/22 20:08:28 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			count = str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			count = str[i] - 'A' + 1;
		else
			count = 1;
		while (count--)
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		repeat_alpha(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}