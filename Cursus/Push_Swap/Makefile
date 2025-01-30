NAME = push_swap
BONUS_NAME = checker

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

CBONUS =	src_bonus/check_args_bonus.c \
			src_bonus/do_push_swap_bonus.c \
			src_bonus/free_functions_bonus.c \
			src_bonus/ft_move_bonus.c \
			src_bonus/lst_utils_bonus.c \
			src_bonus/main_bonus.c \
			src_bonus/operations_bonus.c \
			src_bonus/operations2_bonus.c \
			src_bonus/utils_bonus.c

OBJDIR = obj
OBJFILES = $(CFILES:src/%.c=$(OBJDIR)/%.o)
BONUS_OBJFILES = $(CBONUS:src_bonus/%.c=$(OBJDIR)/%.o)

LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJFILES) $(LIBFT)
	@gcc -Wall -Wextra -Werror -g $(OBJFILES) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJFILES) $(LIBFT)
	@gcc -Wall -Wextra -Werror -g $(BONUS_OBJFILES) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	@make -C Libft

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@gcc -Wall -Wextra -Werror -g -c $< -o $@

$(OBJDIR)/%.o: src_bonus/%.c | $(OBJDIR)
	@gcc -Wall -Wextra -Werror -g -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re