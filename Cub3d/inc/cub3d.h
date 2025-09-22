/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/09/19 11:59:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TEX_SIZE 64
# define MAP_SIZE 24

# define ESC_KEY MLX_KEY_ESCAPE
# define W_KEY MLX_KEY_W
# define A_KEY MLX_KEY_A
# define S_KEY MLX_KEY_S
# define D_KEY MLX_KEY_D
# define LEFT_ARROW MLX_KEY_LEFT
# define RIGHT_ARROW MLX_KEY_RIGHT

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

typedef struct s_img
{
	mlx_image_t	*img_ptr;
	uint32_t	*data;
	int			width;
	int			height;
}	t_img;

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
}	t_texture;

typedef mlx_texture_t	t_tex;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
}	t_ray;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_texture	tex;
	t_player	player;
	char		**map;
	int			map_width;
	int			map_height;
	int			win_width;
	int			win_height;
	char		**sprites;
	int			sprite_count;
}	t_game;

/* Main functions */
int			main(int argc, char **argv);
void		ft_init_game(t_game *game);
void		ft_init_player(t_game *game);
void		ft_set_player_direction(t_game *game, char direction);

/* Parser functions */
int			ft_parse_file(char *filename, t_game *game);
int			ft_parse_textures(char *line, t_game *game);
int			ft_parse_colors(char *line, t_game *game);
int			ft_parse_resolution(char *line, t_game *game);
int			ft_parse_sprite(char *line, t_game *game);
int			ft_parse_map(int fd, t_game *game);
int			ft_parse_map_with_first_line(int fd, t_game *game, char *first_line);
int			ft_is_valid_element(char c);
int			ft_validate_map(t_game *game);
int			ft_load_textures(char *filename, t_game *game);

/* Raycasting functions */
void		ft_raycasting(t_game *game);
void		ft_init_ray(t_game *game, t_ray *ray, int x);
void		ft_calculate_step_and_side_dist(t_game *game, t_ray *ray);
void		ft_perform_dda(t_game *game, t_ray *ray);
void		ft_calculate_draw_limits(t_ray *ray, int win_height);

/* Render functions */
void		ft_render_frame(void *param);
void		ft_draw_vertical_line(t_game *game, int x, t_ray *ray);
uint32_t	ft_get_texture_color(t_game *game, t_ray *ray, int y);
void		ft_put_pixel(t_game *game, int x, int y, uint32_t color);

/* Texture functions */
t_tex		*ft_get_wall_texture(t_game *game, t_ray *ray);
void		ft_calculate_texture_coords(t_game *game, t_ray *ray,
				t_tex *texture, int y);

/* Event functions */
void		ft_key_press(mlx_key_data_t keydata, void *param);
void		ft_close_window(void *param);
void		ft_move_player(t_game *game, double move_x, double move_y);
void		ft_rotate_player(t_game *game, double angle);

/* Utils functions */
void		ft_error_exit(char *msg);
uint32_t	ft_get_color_from_rgb(int r, int g, int b);
char		**ft_split_and_trim(char *str, char delimiter);
void		ft_free_split(char **split);

/* Cleanup functions */
void		ft_cleanup_game(t_game *game);
void		ft_cleanup_textures(t_game *game);
void		ft_cleanup_map(t_game *game);

#endif
