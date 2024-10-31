/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/31 03:00:53 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
	int			width;
	int			height;
	int			width_px;
	int			height_px;
	int			player_n;
	t_coords	player_pos;
	int			exit_n;
	t_coords	exit_pos;
	int			collect_n;
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*img_bg;
	mlx_image_t	*img_wall[NUM_WALL_TEXTURES];
	mlx_image_t	*img_player;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit_open;
	mlx_image_t	*img_exit_closed;
	int			move_count;
	mlx_image_t *counter_bg;
	int			frame_count;
}				t_game;

int			check_type(char *name);
int			check_chars(t_map *map);
int			check_rect(char **map_data);
int			check_frame(t_map *map);
int			check_path(t_map *map);

void		find_pos(t_map *map);
t_map		*get_map(char **map_data, char *file);
t_map		*load_create_map(char *file);
void		ft_free_exit(char **map_data, t_map *map);
void		flood_fill(t_map *map, char **map_data, int y, int x);

char		**copy_map_data(char **data, int height, int width);
void		free_matrix(void **matrix, int height);
void		update_flags(t_map *map);
mlx_image_t	*select_wall_texture(int x, int y, t_game *game);
int			check_map(t_map *map);

void		ft_hook(void *param);
int			charge_textures(t_game *game);
void		handle_input(t_game *game);
void		handle_movement(t_game *game, t_coords old_pos, t_coords new_pos);

void		render_map(t_game *game);
void		render_tile(t_game *game, int i, int j);
void		cleanup(t_game *game);
void		free_textures(t_game *game);

void		init_game_struct(t_game *game);
void		init_game(t_game *game, t_map *map);

void		display_move_count(t_game *game);
void		mlx_image_to_color(mlx_image_t *img, uint32_t color);

#endif