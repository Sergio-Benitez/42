# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:37:52 by sbenitez          #+#    #+#              #
#    Updated: 2024/11/25 23:08:20 by sbenitez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES =	src/mandatory/free_functions.c \
			src/mandatory/game_hooks.c \
			src/mandatory/init_main.c \
			src/mandatory/map_checks.c \
			src/mandatory/map_utils.c \
			src/mandatory/textures.c

CBONUS =	src/bonus/free_functions_bonus.c \
			src/bonus/game_hooks_bonus.c \
			src/bonus/init_main_bonus.c \
			src/bonus/map_checks_bonus.c \
			src/bonus/map_utils_bonus.c \
			src/bonus/textures_bonus.c

LIBFT = Libft/libft.a
MLX42 = MLX42/build/libmlx42.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm  -DDEBUG=ON -o $(NAME)

bonus: $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CBONUS) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

debug: $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address

bbug:
	@gcc -Wall -Wextra -Werror $(CBONUS) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address

$(LIBFT):
	@make -C Libft

$(MLX42):
	@make -C MLX42/build/

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft

re: fclean all
rebug: fclean debug

.PHONY: all clean fclean re