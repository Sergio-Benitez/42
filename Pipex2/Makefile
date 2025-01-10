NAME = pipex

CFILES =	src/main.c \
			src/process_path.c

LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C Libft

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re