NAME = philo

CFILES =	src/data_init.c \
			src/dinner_start.c \
			src/main.c \
			src/monitor_routine.c \
			src/philo_routine.c \
			src/utils.c \
			src/utils2.c \

OBJDIR = obj
OBJFILES = $(CFILES:src/%.c=$(OBJDIR)/%.o)


all: $(NAME)

$(NAME): $(OBJFILES)
	@gcc -Wall -Wextra -Werror -g $(OBJFILES) -o $(NAME)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@gcc -Wall -Wextra -Werror -g -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re