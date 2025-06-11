/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:08:56 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 17:34:05 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/inc/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>

# define WORD 0
# define SQ 1
# define DQ 2
# define PI 3
# define RR1 4
# define RR2 5
# define LR1 6
# define LR2 7
# define LOL 999

extern int	g_signal_flag;

typedef struct s_xpnd
{
	int		start;
	int		end;
	char	*var;
	char	*value;
}				t_xpnd;

typedef struct s_token
{
	char			*tkn;
	int				type;
	bool			join;
	bool			expand;
	struct s_token	*next;
}				t_token;

typedef struct s_cmd
{
	char			**args;
	char			*infile;
	char			*delimiter;
	char			*outfile;
	bool			append;
	bool			hd;
	bool			is_btn;
	int				exit_status;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_shell
{
	char	*input;
	char	**env;
	int		exit_status;
	int		last_exit_st;
	t_token	*token;
	t_cmd	*cmd_lst;
}				t_shell;

//CHECK_SYNTAX.C

void	ft_pipe_syntax(void);
int		ft_check_pipe(t_shell *shell);
int		ft_check_redir(t_shell *shell);
void	ft_check_syntax(t_shell *shell);

// CLEAN.C //

void	ft_free_matrix(char **matrix);
void	ft_free_tknlst(t_token **token);
void	ft_free_cmdlst(t_cmd **cmd_lst);
void	ft_cleanup_shell(t_shell *shell);
void	ft_clean(char **matrix, t_token *token, t_shell *shell);

// CLEAN2.C

void	ft_free_cmd_args(t_cmd *cmd);
void	ft_free_cmd_files(t_cmd *cmd);

// COMMANDS_UTILS.C

int		ft_strcmp(char *s1, char *s2);
int		ft_count_args(t_token *token);
int		ft_isbuiltin(char *str);
int		ft_has_commands(t_shell *shell);

// DEQUOTIZE.C

char	*ft_remove_quotes(char *tkn);
void	ft_dequotize(t_shell *shell);

// EXEC_BUILTINS.C

void	execute_builtin(t_shell *ms, t_cmd *cmd, int prevfd);

// EXEC_CD_UTILS.C

int		ft_check_errors(t_shell *shell, char *oldpwd, char *path);
int		ft_update_pwd(t_shell *shell, char *oldpwd, char *pwd);
int		ft_check_home_error(t_shell *shell, char *home, char *oldpwd);
void	ft_update_home(t_shell *shell, char *oldpwd, char *pwd);

// EXEC_CD.C

int		cd_path(t_shell *shell, char *path);
int		cd_home(t_shell *shell);
int		cd_oldpwd(t_shell *shell);
int		exec_cd(t_shell *shell, t_cmd *cmd);

// EXEC_ECHO.C

int		ft_check_flag(char *s);
int		do_echo(t_cmd *cmd);
int		exec_echo(t_cmd *cmd);

// EXEC_ENV.C

int		exec_env(t_shell *shell);
char	**ft_modify_existing_env(char **env, char *str, int index);

// EXEC_EXIT.X

int		ft_isnum(char *str);
void	free_exit(t_shell *ms);
void	exec_exit(t_shell *ms, t_cmd *cmd, int prevfd);

// EXEC_EXPORT_UTILS.C
int		ft_search_env(char **env, char *str);
char	*ft_get_key(char *str);
int		ft_size_matrix(char **env);
void	ft_swap(char **s1, char **s2);
int		ft_strcmp_order(const char *s1, const char *s2);

// EXEC_EXPORT_UTILS2.C

char	*ft_find_plus_equal(char *str);
char	**ft_create_new_env(char **env, char *str);
char	*ft_process_new_var_string(char *str);
char	*ft_create_appended_var(char *str, char *old_val, char *plus_pos);
char	**ft_append_env_value(char **env, char *str, int index);

// EXEC_EXPORT.C

int		ft_check_env(char *str);
char	**ft_add_modify_env(char **env, char *str, int flag);
void	ft_sort_matrix(char **matrix);
void	ft_print_export(char **env);
int		exec_export(t_shell *shell, t_cmd *cmd);

// EXEC_PWD.C

int		exec_pwd(void);

// EXEC_UNSET.C

char	**ft_remove_env(char **env, char *str);
int		exec_unset(t_shell *shell, t_cmd *cmd);

// EXECUTER_COMMAND.C

void	free_paths(char **paths, int i);
char	*ft_search_in_paths(char **paths, char *comm);
char	*ft_path(char *path, char **comm);
void	ft_handle_command_execution(t_shell *shell, t_cmd *cmd, char *path);
void	execute_command(t_shell *shell, t_cmd *cmd);

// EXECUTER.C

void	child_process(t_cmd *cmd, int prevfd, int pipefd[2], t_shell *ms);
void	parent_process(t_shell *ms, int *prevfd, int pipefd[2]);
void	ft_wait_all_processes(pid_t *pids, t_shell *ms);
pid_t	ft_exec_single_cmd(t_cmd *cmd, int *prevfd, int *pipefd, t_shell *ms);
void	ft_exec_commands(t_shell *ms);

// EXPAND_EXITSTATUS.C

char	*ft_middle_case(char *token, char *dollar_pos, char *status_str);
void	ft_replace_start(char **token, char *status_str, char *dollar_pos);
void	ft_process_dollarquest(t_token *token, char *dollar_pos, char *sts_str);
void	ft_expand_exitstatus(t_shell *shell, t_token *token);

// EXPAND_UTILS.C //

int		ft_intstrchr(const char *s, int c);
int		ft_find_end(char *tkn);
t_xpnd	*ft_init_expand(void);
char	*ft_substr_malloc(const char *input, int start, int len);
void	ft_free_expand(t_xpnd *xpnd);

// EXPAND_VAR.C //

char	*ft_getenv(char **env, char *var);
int		ft_find_dollar(t_shell *shell);
void	ft_insert_exp(t_xpnd *xpnd, t_token *t);
void	ft_expand_token(t_shell *shell, t_token *token);
void	ft_expand_var(t_shell *shell);

// GET_COMMANDS.C //

int		ft_cmdsize(t_cmd *lst);
void	ft_fill_cmd(t_shell *shell, t_token *token, t_token **next_token);
void	ft_process_token(t_shell *shell, t_token **temp);
int		ft_has_commands(t_shell *shell);
int		ft_get_commands(t_shell *shell);

// HEREDOC_UTILS.C

char	*ft_expand_variable(int *i, char *buffer, char **env, int exit_st);
char	*ft_not_expand(int *i, char *buffer);
char	*ft_expand_heredoc(char *buffer, char **env, int exit_st);

// INIT_SHELL.C

t_shell	*ft_init_shell(char **env);

// LIST_UTILS.C

void	ft_addback_tkn(t_token **lst, char *tkn, int type);
void	ft_addback_cmd(t_cmd **lst);
void	ft_update_join(t_token **lst);

// MAIN.C

int		ft_read_input(t_shell *shell);
void	ft_minishell(t_shell *shell);

// PROCESS_REDIRECTION.C //

void	ft_process_redir(t_shell *shell, t_token *token, t_token **next_token);
void	ft_process_input(t_cmd *cmd, t_token *token);
void	ft_process_output(t_cmd *cmd, t_token *token);
void	ft_process_append(t_cmd *cmd, t_token *token);
void	ft_process_heredoc(t_cmd *cmd, t_token *token);

// REDIRECTIONS.C

int		ft_redir_heredoc(t_shell *shell, t_cmd *cmd);
int		ft_redir_infile(char *infile);
int		ft_redir_outfile(char *outfile, int append);
int		ft_redirections(t_shell *shell, t_cmd *cmd);

// SIGNALS.C

void	ft_check_exitstat(int status, t_shell *ms);
void	ft_handle_backslash(int signum);
void	ft_handle_sigint(int signum);
void	ft_setup_signals(void);

// TKNIZE_QUOTES.C //

void	ft_closed_error(char *s);
int		ft_dquote_tkn(t_shell *shell, int *i);
int		ft_squote_tkn(t_shell *shell, int *i);
int		ft_quotes(t_shell *shell, int *i);
void	ft_join_token(t_shell *shell);

// TOKENIZE.C

void	ft_redir_tkn(t_shell *shell, int *i);
void	ft_word_tkn(t_shell *shell, int *i);
void	ft_tokenize(t_shell *shell);

// UTILS.C //

void	ft_exit_error(char *error);
void	*safe_malloc(size_t bytes);
void	ft_print_tokens(t_token *token);
char	**ft_copy_env(char **env);
void	ft_print_cmdlst(t_cmd *cmd_lst);

#endif