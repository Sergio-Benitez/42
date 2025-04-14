/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:28:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/14 14:55:30 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_free_tknlst(t_token **token)
{
	t_token	*temp;

	while (*token)
	{
	//	printf("deleted token\n");
		temp = (*token)->next; // Guardar el siguiente nodo
		free((*token)->tkn);   // Liberar el contenido del token
		free(*token);        // Liberar el nodo actual
		*token = temp;       // Avanzar al siguiente nodo
	}
	*token = NULL;
}
void	ft_free_expand(t_xpnd *xpnd)
{
	if (xpnd)
	{
		if (xpnd->var)
			free(xpnd->var);
		if (xpnd->value)
			free(xpnd->value);
		free(xpnd);
	}
}

void	ft_clean(char **matrix, t_token *token, t_shell *shell)
{
	if (matrix)
		ft_free_matrix(matrix);
	if (token)
		ft_free_tknlst(&token);
	if (shell)
		free(shell);
}