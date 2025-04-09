/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:54:33 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/09 15:49:12 by sbenitez         ###   ########.fr       */
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
        printf("Token: [%s]   Type: [%d]\n", token->tkn, token->type);
        token = token->next;
    }
}
