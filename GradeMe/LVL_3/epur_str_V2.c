/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:35:10 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/05 11:50:42 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void epur_str(char *s)
{
	int i = 0;
	int space = 0;

	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i])
	{
		if (space == 1)
		{
			write(1, " ", 1);
			space = 0;
		}
		while (s[i] && (s[i] != ' ' && s[i] != '\t'))
			write(1, &s[i++], 1);
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		{
			i++;
			space = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		epur_str(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}