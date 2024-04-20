/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:34:15 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/18 22:17:19 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 0)
	{
		while (argv[0][i] != '\0')
		{
			write(1, &argv[0][i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
}
