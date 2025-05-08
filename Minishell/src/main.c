/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:06:58 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/08 19:27:03 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_read_input(t_shell *shell)
{
	if (shell->exit_status != 130)
		shell->last_exit_st = shell->exit_status;
	ft_setup_signals();
	shell->input = readline("minishell> ");
	if (!shell->input)
	{
		ft_putstr_fd("exit\n", 1);
		return (0);
	}
	if (g_signal_flag)
	{
		shell->exit_status = g_signal_flag;
		shell->last_exit_st = g_signal_flag;
	}
	else
		shell->exit_status = 0;
	if (ft_strncmp(shell->input, "", 1))
		add_history(shell->input);
	return (1);
}

void	ft_minishell(t_shell *shell)
{
	while (1)
	{
		if (!ft_read_input(shell))
			break ;
		ft_tokenize(shell);
		ft_check_syntax(shell);
		if (ft_find_dollar(shell))
			ft_expand_var(shell);
		ft_dequotize(shell);
		ft_print_tokens(shell->token);
		if (shell->token && ft_get_commands(shell))
			ft_print_cmdlst(shell->cmd_lst);
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
