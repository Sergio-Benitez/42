/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:35:30 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/28 11:46:44 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_get_input(t_shell *shell)
{
	while ((shell->input = readline("minishell> ")) != NULL)
	{
		shell->exit_status = 0;
		if (ft_strncmp(shell->input, "", 1))
			add_history(shell->input);
		ft_tokenize(shell);
		ft_check_syntax(shell);
		if (ft_find_dollar(shell))
			ft_expand_var(shell);
		ft_dequotize(shell);
		
		ft_print_tokens(shell->token);
//		printf("\033[0;33mExit status: %d\n\033[0;37m", shell->exit_status);
		free(shell->input);
		shell->last_exit_st = shell->exit_status;
		if (shell->token != NULL)
			ft_free_tknlst(&shell->token);
	}
}
