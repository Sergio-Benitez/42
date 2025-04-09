/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:38:47 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/09 18:38:11 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_addback_tkn(t_token **lst, char *tkn, int type)
{
	t_token	*new;
	t_token	*temp;

	if (!lst || !tkn)
		return;
	new = safe_malloc(sizeof(t_token));
	new->tkn = ft_strdup(tkn);
//	free(tkn);
	new->type = type;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
