NAME = push_swap

CFILES =	src/check_args.c \
			src/free_functions.c \
			src/ft_move.c \
			src/lst_utils.c \
			src/lst_utils2.c \
			src/lst_utils3.c \
			src/main.c \
			src/operations.c \
			src/operations2.c \
			src/utils.c

OBJDIR = obj
OBJFILES = $(CFILES:src/%.c=$(OBJDIR)/%.o)

LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJFILES) $(LIBFT)
	@gcc -Wall -Wextra -Werror -g $(OBJFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C Libft

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@gcc -Wall -Wextra -Werror -g -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR) $(NAME)

fclean: clean
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re