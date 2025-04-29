/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:35:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/29 20:06:31 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_get_input(t_shell *shell)
{
	while (1)
	{
		shell->input = readline("minishell> ");
		if (!shell->input)
			break ; //libera
		shell->exit_status = 0;
		if (ft_strncmp(shell->input, "", 1))
			add_history(shell->input);
		ft_tokenize(shell);
		ft_check_syntax(shell);
		if (ft_find_dollar(shell))
			ft_expand_var(shell);
		ft_dequotize(shell);
		if (shell->token)
		{
			//if (ft_get_commands(shell));
				//pase a ejecutor
				//libera cosas
		}
		//libera
		ft_print_tokens(shell->token);
		free(shell->input);
		shell->last_exit_st = shell->exit_status;
		if (shell->token != NULL)
			ft_free_tknlst(&shell->token);
	}
}
