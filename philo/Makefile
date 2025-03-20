NAME = philo
#BONUS_NAME = philo_bonus

CFILES =	src/data_init.c \
			src/main.c \
			src/safe_functions.c \
			src/utils.c \
			src/dinner_start.c \
			src/monitor_routine.c \

#CBONUS =	src_bonus/check_args_bonus.c \
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
#BONUS_OBJFILES = $(CBONUS:src_bonus/%.c=$(OBJDIR)/%.o)


all: $(NAME)

$(NAME): $(OBJFILES)
	@gcc -Wall -Wextra -Werror -g $(OBJFILES) -o $(NAME)

#bonus: $(BONUS_NAME)

#$(BONUS_NAME): $(BONUS_OBJFILES)
#	@gcc -Wall -Wextra -Werror -g $(BONUS_OBJFILES) -o $(BONUS_NAME)


$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@gcc -Wall -Wextra -Werror -g -c $< -o $@

#$(OBJDIR)/%.o: src_bonus/%.c | $(OBJDIR)
#	@gcc -Wall -Wextra -Werror -g -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) 
#	$(BONUS_NAME)
	@make fclean -C

re: fclean all

.PHONY: all clean fclean re