/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:08:56 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/09 18:55:03 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/inc/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/* # define WORD 0
# define QS 1
# define QD 2
# define PI 3
# define R1 4
# define R2 5
# define L1 6
# define L2 7 */

typedef struct s_token
{
	char			*tkn;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_shell
{
	char	*input;
	char	**env;
	t_token	*token;
}				t_shell;

// CLEAN.C

void	ft_free_matrix(char **matrix);
void	ft_free_tknlst(t_token **token);
void	ft_clean(char **matrix, t_shell *shell, t_token *token);

// GET_INPUT.C

void	ft_tokenize(t_shell *shell);
void	ft_get_input(t_shell *shell);

// INIT_SHELL.C

t_shell	*ft_init_shell(char **env);

// LIST_UTILS.C

void	ft_addback_tkn(t_token **lst, char *tkn, int type);

// MAIN.C

char	**ft_copy_env(char **env);

// UTILS.C

void	ft_exit_error(char *error);
void	*safe_malloc(size_t bytes);
void	ft_print_tokens(t_token *token);

// TKNIZE_QUOTES.C

int		ft_dquote_tkn(t_shell *shell, int *i);
int		ft_squote_tkn(t_shell *shell, int *i);
int		ft_quotes(t_shell *shell, int *i);

#endif