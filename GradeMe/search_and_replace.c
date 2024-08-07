/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:50:34 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/07 19:38:52 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printstr(char *str)
{
	int	i;

	i= 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

char	*search_and_replace(char *str, char b, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == b)
			str[i] = c;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[2][i] != '\0' || argv[3][i] != '\0')
	{
		if (i > 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		i++;
	}
	printstr(search_and_replace(argv[1], argv[2][0], argv[3][0]));
	return (0);
}