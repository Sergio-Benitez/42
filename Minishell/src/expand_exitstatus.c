/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exitstatus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:45:43 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/06 17:02:29 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_middle_case(char *token, char *dollar_pos, char *status_str)
{
	char	*prefix;
	char	*suffix;
	char	*temp;
	char	*result;
	int		prefix_len;

	prefix_len = dollar_pos - token;
	prefix = ft_substr(token, 0, prefix_len);
	suffix = ft_strdup(dollar_pos + 2);
	temp = ft_strjoin(prefix, status_str);
	result = ft_strjoin(temp, suffix);
	free(prefix);
	free(suffix);
	free(temp);
	return (result);
}

void	ft_replace_start(char **token, char *status_str, char *dollar_pos)
{
	char	*result;

	if (ft_strlen(*token) > 2)
	{
		result = ft_strjoin(status_str, dollar_pos + 2);
		free(*token);
		*token = result;
	}
	else
	{
		free(*token);
		*token = ft_strdup(status_str);
	}
}

void	ft_expand_exitstatus(t_shell *shell, t_token *token)
{
	char	*status_str;
	char	*result;
	char	*dollar_pos;
	int		pos;

	dollar_pos = ft_strnstr(token->tkn, "$?", ft_strlen(token->tkn));
	if (!dollar_pos)
		return ;
	status_str = ft_itoa(shell->last_exit_st);
	if (!status_str)
		return ;
	pos = dollar_pos - token->tkn;
	if (pos == 0)
		ft_replace_start(&token->tkn, status_str, dollar_pos);
	else
	{
		result = ft_middle_case(token->tkn, dollar_pos, status_str);
		free(token->tkn);
		token->tkn = result;
	}
	free(status_str);
}
