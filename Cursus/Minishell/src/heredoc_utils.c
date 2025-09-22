/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:33:31 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/29 17:57:50 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_expand_variable(int *i, char *buffer, char **env, int exit_st)
{
	int		start;
	char	*var;
	char	*value;

	(*i)++;
	if (buffer[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(exit_st));
	}
	start = *i;
	while (buffer[*i] && (buffer[*i] == '_' || ft_isalnum(buffer[*i])))
		(*i)++;
	if (start == *i)
		return (ft_strdup("$"));
	var = ft_substr_malloc(buffer, start, (*i) - start + 1);
	value = ft_getenv(env, var);
	free(var);
	if (!value)
		return (ft_strdup(""));
	return (value);
}

char	*ft_not_expand(int *i, char *buffer)
{
	int	start;

	start = *i;
	while (buffer[*i] && buffer[*i] != '$')
		(*i)++;
	if (buffer[*i] == '$')
	{
		if (!buffer[*i + 1])
			(*i)++;
		else if (buffer[*i + 1] && !(ft_isalpha(buffer[*i + 1])
				|| buffer[*i + 1] == '_' || buffer[*i + 1] == '?'))
			buffer[*i] = '\0';
	}
	return (ft_substr_malloc(buffer, start, (*i) - start + 1));
}

char	*ft_expand_heredoc(char *buffer, char **env, int exit_st)
{
	char	*aux;
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '$' && buffer[i + 1] && (ft_isalpha(buffer[i + 1])
				|| buffer[i + 1] == '_' || buffer[i + 1] == '?'))
			aux = ft_expand_variable(&i, buffer, env, exit_st);
		else
			aux = ft_not_expand(&i, buffer);
		temp = ft_strjoin(result, aux);
		free(result);
		free(aux);
		result = temp;
	}
	return (free(buffer), result);
}
