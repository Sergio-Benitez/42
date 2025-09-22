/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:29 by sbenitez          #+#    #+#             */
/*   Updated: 2025/06/09 12:58:42 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 96

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
	mlx_texture_t	*bg;
	mlx_image_t	*img_bg;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_player;
	mlx_image_t	*img_collect;
	mlx_image_t	*img_exit;
	int			move_count;
	int			frame_count;
}				t_game;

void		free_matrix(void **matrix, int height);
void		ft_free_exit(char **map_data, t_map *map);
void		free_textures(t_game *game);
void		cleanup(t_game *game);
int			check_map(t_map *map);

void		ft_hook(void *param);
void		handle_input(t_game *game);
void		handle_movement(t_game *game, t_coords old_pos, t_coords new_pos);
void		update_flags(t_map *map);

void		init_game_struct(t_game *game);
void		init_game(t_game *game, t_map *map);

int			check_type(char *name);
int			check_chars(t_map *map);
int			check_rect(char **map_data);
int			check_frame(t_map *map);
int			check_path(t_map *map);

void		find_pos(t_map *map);
t_map		*get_map(char **map_data, char *file);
t_map		*load_create_map(char *file);
char		**copy_map_data(char **data, int height, int width);
void		flood_fill(t_map *map, char **map_data, int y, int x);

int			charge_textures(t_game *game);
void		render_map(t_game *game);
void		render_tile(t_game *game, int i, int j);

#endif