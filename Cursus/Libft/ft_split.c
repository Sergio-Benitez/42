/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:13:56 by sbenitez          #+#    #+#             */
/*   Updated: 2024/05/06 19:37:14 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
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

char	*ft_wordalloc(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	word = NULL;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
		{
			len = 0;
			while (s[i] != c)
			{
				i++;
				len++;
			}
			word = ft_substr(s, i, len);
		}
		i++;
	}
	return (word);
}

/*char	**ft_split(char const *s, char c)
{
	char	**splitted;//	splitted[i][j]
	int		i;
	int		cont;

	i = 0;
	cont = ft_wordcount(s, c);
	
	if (s == NULL)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * (cont + 1));
	if (!splitted)
		return (NULL);
	splitted[cont] = NULL;
	while (i < cont)
	{
		splitted[i] = ft_wordalloc(s, c);
	}
}*/

#include <stdio.h>

int	main(void)
{
	const char	str[] = "   No vea lo cara   que está  Málaga   ";
	printf("%s", ft_wordalloc(str, ' '));
	return (0);
}