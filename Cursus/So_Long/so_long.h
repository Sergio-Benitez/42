/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/10/24 18:26:47 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>

/*
typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}				mlx_t;
*/
typedef struct s_map
{
	char		*filename;
	int			width;
	int			height;
	char		**data;
	int			player_n;
	int			player_y;
	int			player_x;
	int			exit_n;
	int			exit_y;
	int			exit_x;
	int			collect_n;
}				t_map;


int		check_map(t_map *map);
int		check_type(char *name);
int		check_chars(t_map *map);
int		check_rect(char **map_data);
int		check_frame(t_map *map);
int		check_path(t_map *map);

void	find_pos(t_map *map);
t_map	*get_map(char **map_data, char *file);
t_map	*load_create_map(char *file);
void	ft_free_exit(char **map_data, t_map *map);
void	flood_fill(t_map *map, char **map_data, int y, int x);
char	**copy_map_data(char **data, int height, int width);
void	free_map_data(char **aux, int height);

#endif