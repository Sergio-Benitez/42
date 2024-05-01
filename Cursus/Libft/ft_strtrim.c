/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:02 by sbenitez          #+#    #+#             */
/*   Updated: 2024/05/01 17:20:00 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL && i < j)
		i++;
	while (ft_strchr(set, s1[j]) != NULL && i < j)
		j--;
	ptr = malloc(j - i + 2);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], j - i + 2);
	return (ptr);
}
