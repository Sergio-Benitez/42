/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:06:58 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/30 13:58:20 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_minishell(t_shell *shell)
{
	while (1)
	{
		shell->input = readline("minishell> ");
		if (!shell->input)
		{
			ft_cleanup_shell(shell);
			break ;
		}
		shell->exit_status = 0;
		if (ft_strncmp(shell->input, "", 1))
			add_history(shell->input);
		ft_tokenize(shell);
		ft_check_syntax(shell);
		if (ft_find_dollar(shell))
			ft_expand_var(shell);
		ft_dequotize(shell);
		ft_print_tokens(shell->token); // PRINT TOKENS
		if (shell->token)
		{
			if (ft_get_commands(shell))
				ft_print_cmdlst(shell->cmd_lst); // PRINT COMMANDS
				//pase a ejecutor
				//libera cosas
		}
		ft_cleanup_shell(shell);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	shell = ft_init_shell(ft_copy_env(env));
	ft_minishell(shell);
	ft_clean(shell->env, NULL, shell);
	return (0);
}
