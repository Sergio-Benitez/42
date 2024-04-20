/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:47:27 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/06 16:26:26 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 96) && (str[i] < 123))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
/*#include <stdio.h>

int	main()
{
	char	strg[] = "macarrones";
	printf("%s", ft_strupcase(strg));
	return (0);
}*/
