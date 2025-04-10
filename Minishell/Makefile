NAME = minishell

CFILES =	src/clean.c \
			src/get_input.c \
			src/init_shell.c \
			src/list_utils.c \
			src/main.c \
			src/tknize_quotes.c \
			src/tokenize.c \
			src/utils.c

LIBFT = inc/libft/libft.a

OBJDIR = obj
OBJFILES = $(CFILES:src/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

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