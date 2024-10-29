# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:37:52 by sbenitez          #+#    #+#              #
#    Updated: 2024/10/29 17:38:51 by sbenitez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES =	src/checker.c \
			src/main.c \
			src/print_window.c \
			src/render_things.c \
			src/utils.c \
			src/utils2.c

#CBONUS =	src_bonus/ft_check_map.c \
			src_bonus/ft_clean.c \
			src_bonus/ft_init.c \
			src_bonus/ft_movement.c \
			src_bonus/ft_read_map.c \
			src_bonus/ft_render.c \
			src_bonus/ft_render_map.c \
			src_bonus/ft_sprites.c \
			src_bonus/main.c \
			src_bonus/ft_moves.c 

LIBFT = Libft/libft.a
MLX42 = MLX42/build/libmlx42.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm  -DDEBUG=ON -o $(NAME)

#bonus:
#	@gcc -Wall -Wextra -Werror $(CBONUS) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

debug: $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address

bbug:
	@gcc -Wall -Wextra -Werror $(CBONUSA) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address

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