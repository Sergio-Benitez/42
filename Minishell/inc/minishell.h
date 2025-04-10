/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:08:56 by sbenitez          #+#    #+#             */
/*   Updated: 2025/04/11 13:42:16 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/inc/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# define WORD 0
# define SQ 1
# define DQ 2
# define PI 3
# define RR1 4
# define RR2 5
# define LR1 6
# define LR2 7

typedef struct s_token
{
	char			*tkn;
	int				type;
	bool			join;
	bool			expand;
	struct s_token	*next;
}					t_token;

typedef struct s_shell
{
	char	*input;
	char	**env;
	int		exit_status;
	int		last_exit_st;
	t_token	*token;
}				t_shell;

//CHECK_SYNTAX.C

int		ft_check_pipe(t_shell *shell);
int		ft_check_redir(t_shell *shell);
void	ft_check_syntax(t_shell *shell);

// CLEAN.C

void	ft_free_matrix(char **matrix);
void	ft_free_tknlst(t_token **token);
void	ft_clean(char **matrix, t_token *token, t_shell *shell);

// EXPAND_VAR.C

void	ft_expand_var(t_shell *shell);

// GET_INPUT.C

void	ft_get_input(t_shell *shell);

// INIT_SHELL.C

t_shell	*ft_init_shell(char **env);

// LIST_UTILS.C

void	ft_addback_tkn(t_token **lst, char *tkn, int type);
void	ft_update_join(t_token **lst);

// MAIN.C

// UTILS.C

void	ft_exit_error(char *error);
void	*safe_malloc(size_t bytes);
void	ft_print_tokens(t_token *token);
char	**ft_copy_env(char **env);

// TKNIZE_QUOTES.C

int		ft_dquote_tkn(t_shell *shell, int *i);
int		ft_squote_tkn(t_shell *shell, int *i);
int		ft_quotes(t_shell *shell, int *i);
void	ft_join_qtoken(t_shell *shell);

// TOKENIZE.C

void	ft_redir_tkn(t_shell *shell, int *i);
void	ft_word_tkn(t_shell *shell, int *i);
void	ft_tokenize(t_shell *shell);


#endif