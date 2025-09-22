MAKEFLAGS += --no-print-directory

NAME = minishell

CFILES =	src/check_syntax.c \
			src/clean.c \
			src/clean2.c \
			src/commands_utils.c \
			src/dequotize.c \
			src/exec_builtins.c \
			src/exec_cd_utils.c \
			src/exec_cd.c \
			src/exec_echo.c \
			src/exec_env.c \
			src/exec_exit.c \
			src/exec_export_utils.c \
			src/exec_export_utils2.c \
			src/exec_export.c \
			src/exec_pwd.c \
			src/exec_unset.c \
			src/executer_command.c \
			src/executer.c \
			src/expand_exitstatus.c \
			src/expand_utils.c \
			src/expand_var.c \
			src/get_commands.c \
			src/heredoc_utils.c \
			src/init_shell.c \
			src/list_utils.c \
			src/main.c \
			src/process_redirection.c \
			src/redirections.c \
			src/signals.c \
			src/tknize_quotes.c \
			src/tokenize.c \
			src/utils.c

LIBFT = inc/libft/libft.a

OBJDIR = obj
OBJFILES = $(CFILES:src/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJFILES)
	@$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	@make -C inc/libft

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@make clean -C inc/libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C inc/libft

re: fclean all

.PHONY: all clean fclean re
