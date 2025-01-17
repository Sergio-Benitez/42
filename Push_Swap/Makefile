NAME = push_swap

CFILES =	src/check_args.c \
			src/free_functions.c \
			src/lst_utils.c \
			src/lst_utils2.c \
			src/main.c \
			src/operations.c \
			src/utils.c

LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -Wall -Wextra -Werror -g $(CFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C Libft

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re