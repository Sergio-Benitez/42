/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:40:03 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/05 12:27:55 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_shell	*ft_init_shell(char **env)
{
	t_shell	*shell;

	shell = safe_malloc(sizeof(t_shell));
	shell->input = NULL;
	shell->env = env;
	shell->exit_status = 0;
	shell->last_exit_st = 0;
	shell->token = NULL;
	shell->cmd_lst = NULL;
	return (shell);
}
