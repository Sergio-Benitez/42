/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:50:03 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 11:50:38 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_find_plus_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] == '=')
			return (str + i);
		i++;
	}
	return (NULL);
}

char	**ft_create_new_env(char **env, char *str)
{
	char	**new;
	int		size;
	int		i;

	size = ft_size_matrix(env);
	new = malloc(sizeof(char *) * (size + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = ft_process_new_var_string(str);
	new[i + 1] = NULL;
	return (new);
}

char	*ft_process_new_var_string(char *str)
{
	char	*plus_pos;
	char	*result;
	int		key_len;
	int		i;

	plus_pos = ft_find_plus_equal(str);
	if (!plus_pos)
		return (ft_strdup(str));
	key_len = plus_pos - str;
	result = malloc(ft_strlen(str));
	if (!result)
		return (NULL);
	i = 0;
	while (i < key_len)
	{
		result[i] = str[i];
		i++;
	}
	result[key_len] = '=';
	ft_strlcpy(result + key_len + 1, plus_pos + 2, ft_strlen(plus_pos + 2) + 1);
	return (result);
}

char	*ft_create_appended_var(char *str, char *old_val, char *plus_pos)
{
	char	*result;
	char	*temp;
	int		key_len;
	int		i;

	key_len = plus_pos - str;
	temp = ft_strjoin(old_val, plus_pos + 2);
	result = malloc(key_len + 1 + ft_strlen(temp) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < key_len)
	{
		result[i] = str[i];
		i++;
	}
	result[key_len] = '=';
	ft_strlcpy(result + key_len + 1, temp, ft_strlen(temp) + 1);
	free(temp);
	return (result);
}

char	**ft_append_env_value(char **env, char *str, int index)
{
	char	*temp;
	char	*old_value;
	char	*equal_pos;

	temp = ft_find_plus_equal(str);
	if (!temp)
		return (env);
	equal_pos = ft_strchr(env[index], '=');
	if (!equal_pos)
		old_value = ft_strdup("");
	else
		old_value = ft_strdup(equal_pos + 1);
	free(env[index]);
	env[index] = ft_create_appended_var(str, old_value, temp);
	free(old_value);
	return (env);
}
