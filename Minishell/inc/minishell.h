/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:08:56 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/08 15:29:06 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/inc/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct	s_shell
{
	char	*input;
}				t_shell;


// CLEAN.C

void	ft_free_matrix(char **matrix);

// GET_INPUT.C

void	ft_get_input(char **env, t_shell *shell);

// INIT_SHELL.C

t_shell	*ft_init_shell(void);

// UTILS.C

void	ft_exit_error(char *error);
void	*safe_malloc(size_t bytes);

// MAIN.C

char	**ft_copy_env(char **env);

#endif