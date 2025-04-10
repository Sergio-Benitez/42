/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:16:26 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/10 19:16:27 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_find_dollar(t_shell *shell)
{
	t_token	*temp;

	temp = shell->token;
	while (temp)
	{
		if (ft_strchr(temp->tkn, '$') != 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_expand_var(t_shell *shell)
{
	if (ft_find_dollar(shell))
		printf("Dollar encontrao\n");
}