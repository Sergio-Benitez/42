/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:13:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/05/03 19:36:53 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcounter(char const *s, char c)
{
	int	i;
	int cont;

	i = 0;
	cont = 0;
	if (s[0] != c && s[0] != '\0')
		cont = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			cont++;
		i++;
	}
	return (cont);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		j;
	int		k;

	splitted = NULL;
	i = 0;
	j = 0;
	k = 0;
	
}	

/*	while (i < ft_wordcounter(s, c))
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		while (s[k] != c && s[k] != '\0')
		{
			splitted[i][j] = s[k];
			j++;
			k++;
		}
		splitted[i][j] = '\0';
		i++;
		j = 0;
	}
	splitted[i] = NULL;
	return (splitted);
}
*/
