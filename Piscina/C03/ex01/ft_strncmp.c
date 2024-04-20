/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:13:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/03/13 12:48:30 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "Mandolinas";
	char	s2[] = "Camarones";
	unsigned int	n = 4;

	printf("%s", ft_strncmp(s1, s2, n));
	return (0);
}*/
