/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:55:02 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/08 13:35:38 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == ' ' || str[i - 1] == '	')
	{
		i -= 1;
		while (str[i] == ' ' || str[i] == '	')
			i--;
	}
	while (str[i] != ' ' && str[i] != '	' && i != 0)
		i--;
	i += 1;
	while (str[i] && str[i] != ' ' && str[i] != '	')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	last_word(argv[1]);
	return (0);
}