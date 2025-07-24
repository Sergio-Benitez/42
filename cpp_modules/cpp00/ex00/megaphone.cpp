/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:41:13 by sbenitez          #+#    #+#             */
/*   Updated: 2025/07/24 21:04:55 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < argc; i++)
	{
		std::string current = argv[i];
		for (int c = 0; c < current.length(); c++)
			current[c] = std::toupper(current[c]);
		std::cout << current;

		if (i == argc - 1)
			std::cout << std::endl;
		else
			std::cout << " ";
	}
}
