/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:38:47 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/07 13:06:37 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_addback_tkn(t_token **lst, char *tkn, int type)
{
	t_token	*new;
	t_token	*temp;

	if (!lst || !tkn)
		return ;
	new = safe_malloc(sizeof(t_token));
	new->tkn = ft_strdup(tkn);
	new->type = type;
	new->next = NULL;
	new->join = false;
	new->expand = false;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_addback_cmd(t_cmd **lst)
{
	t_cmd	*new;
	t_cmd	*temp;

	new = safe_malloc(sizeof(t_cmd));
	new->args = NULL;
	new->infile = NULL;
	new->outfile = NULL;
	new->delimiter = NULL;
	new->append = false;
	new->hd = false;
	new->is_btn = false;
	new->exit_status = 0;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_update_join(t_token **lst)
{
	t_token	*temp;

	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->join = true;
}
