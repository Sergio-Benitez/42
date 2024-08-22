/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:47:22 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/21 21:33:13 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	wordcounter(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') && (str[i + 1] == ' ' || str[i + 1] == '	' || str[i + 1] == '\n' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_substr(char *str)
{
	
}

char	**ft_split(char *str)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		count;
	char	**split;

	count = wordcounter(str) + 1;
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (k <= count)
		{
			split[k] = (char *)malloc(ft_substr() * sizeof(char));
			k++;
		}
		i++;
	}
	return (split);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int 	i = 0;
	char	**split = ft_split(argv[1]);
	
	while (split[i])
	{
		printf("%s", split[i]);
		i++;
	}
	return (0);
}