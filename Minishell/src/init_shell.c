/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:40:03 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/10 18:11:02 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_shell	*ft_init_shell(char **env)
{
	t_shell	*shell;

	shell = safe_malloc(sizeof(t_shell));
	shell->input = NULL;
	shell->token = NULL;
	shell->env = env;
	shell->exit_status = 0;
	return (shell);
}
