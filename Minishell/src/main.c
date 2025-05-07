/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:06:58 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/07 13:51:18 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_signal_flag;

void	ft_minishell(t_shell *shell)
{
	while (1)
	{
		g_signal_flag = 0;
		shell->input = readline("minishell> ");
		if (!shell->input)
			break ;
		shell->exit_status = 0;
		if (ft_strncmp(shell->input, "", 1))
			add_history(shell->input);
		ft_tokenize(shell);
		ft_check_syntax(shell);
		if (ft_find_dollar(shell))
			ft_expand_var(shell);
		ft_dequotize(shell);
		// DALE CAÑA, JUANMA!!
		ft_print_tokens(shell->token); // PRINT TOKENS
		if (shell->token)
		{
			if (ft_get_commands(shell))
				ft_print_cmdlst(shell->cmd_lst); // PRINT COMMANDS
				//pase a ejecutor
		}
		ft_cleanup_shell(shell);
	}
	ft_cleanup_shell(shell);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	if (!*env)
		return (ft_putendl_fd("minishell: enviroment must not be empty", 2), 1);
	shell = ft_init_shell(ft_copy_env(env));
	ft_minishell(shell);
	ft_clean(shell->env, NULL, shell);
	return (0);
}
