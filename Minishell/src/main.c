/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:06:58 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/09 16:53:17 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ft_copy_env(char **env)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	while (env[i])
		i++;
	cpy = safe_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while(env[i])
	{
		cpy[i] = safe_malloc(sizeof (char) * (ft_strlen(env[i]) + 1));
		j = 0;
		while (env[i][j])
		{
			cpy[i][j] = env[i][j];
			j++;
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	
	(void)argc;
	(void)argv;
	shell = ft_init_shell(ft_copy_env(env));
	ft_get_input(shell);
	ft_clean(shell->env, shell, NULL);
	return (0);
}
