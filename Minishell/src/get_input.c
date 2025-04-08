/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:35:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/08 14:46:08 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_get_input(char **env, t_shell *shell)
{
	(void)env;

	while ((shell->input = readline("minishell> ")) != NULL)
	{
		if (*shell->input)  // Si la línea no está vacía
			add_history(shell->input);  // Agrega la línea al historial
		printf("You entered: %s\n", shell->input);
		free(shell->input);  // readline usa malloc, así que hay que liberar la memoria
	}
}
