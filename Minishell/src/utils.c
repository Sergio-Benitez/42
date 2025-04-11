/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:54:33 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/11 12:56:06 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_exit_error(char *error)
{
	printf("%s\n", error);
	exit (EXIT_FAILURE);
}

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		ft_exit_error("Error with the malloc");
	return (ret);
}

void	ft_print_tokens(t_token *token)
{
    while (token)
    {
        printf("Token: [%s]   Type: [%d]   Expand: [%d]\n", token->tkn, token->type, token->expand);
        token = token->next;
    }
}
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
