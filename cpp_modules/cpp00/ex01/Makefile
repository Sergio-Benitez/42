NAME = phonebook

INCLUDE = -I ./inc

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
CC = c++

SRC_DIR := src
OBJDIR := obj

SRCS := $(SRC_DIR)/phonebook.cpp \
        $(SRC_DIR)/contact.cpp \
        $(SRC_DIR)/main.cpp

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(INCLUDE) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
