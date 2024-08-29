/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:37:55 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/29 12:56:24 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		while (s1[i] != s2[j] && s2[j])
		{
			j++;
			if (s1[i] == s2[j] && s1[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (checker(argv[1], argv[2]) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}