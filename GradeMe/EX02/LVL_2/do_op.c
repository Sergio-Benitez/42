/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:23:54 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/28 20:44:02 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	operations(int first, char op, int last)
{
	if (op == '+')
		return (first + last);
	else if (op == '-')
		return (first - last);
	else if (op == '*')
		return (first * last);
	else if (op == '/')
		return (first / last);
	else if (op == '%')
		return (first % last);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 4)
		printf("%d", operations(atoi(argv[1]), argv[2][0], atoi(argv[3])));
	printf("\n");
	return (0);
}