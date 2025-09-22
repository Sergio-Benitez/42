/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:23:11 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 11:09:47 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_search_env(char **env, char *str)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], str, ft_strlen(str))
			&& (env[i][ft_strlen(str)] == '='
			|| env[i][ft_strlen(str)] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	key = ft_strdup(str);
	while (key[i] && key[i] != '+' && key[i] != '=')
		i++;
	key[i] = '\0';
	return (key);
}

int	ft_size_matrix(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_strcmp_order(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
