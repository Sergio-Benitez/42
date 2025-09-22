# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#              #
#    Updated: 2025/09/19 11:59:40 by sbenitez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

# Directories
SRCDIR		= src
INCDIR		= inc
OBJDIR		= obj
LIBFTDIR	= ../Libft
MLX42DIR	= MLX42

# Source files
SRCFILES	= main.c \
			  init.c \
			  player_init.c \
			  player_direction.c \
			  parser.c \
			  parser_utils.c \
			  color_parser.c \
			  map_parser.c \
			  map_validation.c \
			  raycasting.c \
			  raycasting_utils.c \
			  render.c \
			  texture_utils.c \
			  events.c \
			  utils.c \
			  cleanup.c \
			  texture_loader.c

SRCS		= $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS		= $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))

# Compiler and flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I$(INCDIR) -I$(LIBFTDIR)/inc -I$(MLX42DIR)/include
LIBFT		= $(LIBFTDIR)/libft.a
MLX42		= $(MLX42DIR)/build/libmlx42.a

# MLX42 flags
MLX_FLAGS	= -lglfw -lm -ldl -pthread

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJDIR) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFTDIR)

$(MLX42):
	@echo "$(GREEN)Building MLX42...$(RESET)"
	@cmake -S $(MLX42DIR) -B $(MLX42DIR)/build > /dev/null 2>&1
	@cmake --build $(MLX42DIR)/build -j4 > /dev/null 2>&1

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)
	@rm -rf $(MLX42DIR)/build

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
