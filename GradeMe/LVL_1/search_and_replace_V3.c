/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:15:45 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/03 12:22:28 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void search_replace(char *str, char a, char b)

{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][1] != '\0' || argv[3][1] != '\0')
			return (write(1, "\n", 1), 0);
		search_replace(argv[1], *argv[2], *argv[3]);
	}
	write(1, "\n", 1);
	return (0);
}