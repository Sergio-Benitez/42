/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/11/26 19:24:25 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define TILE_SIZE 96
# define NUM_WALL_TEXTURES 3

# include "../Libft/inc/libft.h"
# include "../Libft/inc/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct s_map
{
	char		*filename;
	char		**data;
	bool		**update_flags;
	int			invalid_flag;
	int			width;
	int			height;
	int			width_px;
	int			height_px;
	int			player_n;
	t_coords	player_pos;
	int			exit_n;
	t_coords	exit_pos;
	int			collect_n;
	int			enemy_n;
	t_coords	enemy_pos;
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*img_bg;
	mlx_image_t	*img_wall[NUM_WALL_TEXTURES];
	mlx_image_t	*img_player;
	mlx_image_t	*img_player_up;
	mlx_image_t	*img_player_down;
	mlx_image_t	*img_player_left;
	mlx_image_t	*img_player_right;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit_open;
	mlx_image_t	*img_exit_closed;
	mlx_image_t	*img_enemy;
	int			move_count;
	mlx_image_t	*wmoves;
	int			frame_count;
}				t_game;

void		free_matrix(void **matrix, int height);
void		ft_free_exit(char **map_data, t_map *map);
void		free_textures(t_game *game);
void		cleanup(t_game *game);
int			check_map(t_map *map);

void		ft_hook(void *param);
void		handle_input(t_game *game);
void		move_player(t_game *game, t_coords *pos, int dx, int dy);
void		handle_movement(t_game *game, t_coords old_pos, t_coords new_pos);
void		update_flags(t_map *map);

void		init_game_struct(t_game *game);
void		init_game(t_game *game, t_map *map);
void		ft_moves(t_game *game);
void		game_over(t_game *game);

int			check_type(char *name);
int			check_chars(t_map *map);
int			check_rect(char **map_data);
int			check_frame(t_map *map);
int			check_path(t_map *map);

void		find_pos(t_map *map, int y, int x);
t_map		*get_map(char **map_data, char *file);
t_map		*load_create_map(char *file);
char		**copy_map_data(char **data, int height, int width);
void		flood_fill(t_map *map, char **map_data, int y, int x);

int			charge_element_textures(t_game *game);
int			charge_individuals_textures(t_game *game);
mlx_image_t	*select_wall_texture(int x, int y, t_game *game);
void		render_map(t_game *game);
void		render_tile(t_game *game, int i, int j);

#endif