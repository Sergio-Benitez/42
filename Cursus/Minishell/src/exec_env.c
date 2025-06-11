/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:26:49 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 11:48:43 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	exec_env(t_shell *shell)
{
	int	i;

	i = 0;
	ft_add_modify_env(shell->env, "_=/usr/bin/env", 1);
	while (shell->env[i])
	{
		if (ft_strchr(shell->env[i], '='))
			printf("%s\n", shell->env[i]);
		i++;
	}
	return (0);
}

char	**ft_modify_existing_env(char **env, char *str, int index)
{
	free(env[index]);
	env[index] = ft_strdup(str);
	return (env);
}
