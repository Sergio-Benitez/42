/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/11 22:30:04 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*
# ifndef MAX_WIDTH
#  define MAX_WIDTH	15
# endif

# ifndef MAX_HEIGHT
#  define MAX_HEIGHT	15
# endif
*/
# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	char		*filename;
	int			width;
	int			height;
	char		**data;
	int			player_n;
	int			exit_n;
	int			collect_n;
}				t_map;

t_map	*load_create_map(char *file);

int		check_map(t_map *map);
int		check_type(char *name);
int		check_chars(t_map *map);
int		check_rect(char **map_data);
int		check_frame(t_map *map);
int		check_path(t_map *map);

t_map	*get_map(char **map_data, char *file);
void	ft_free_exit(char **map_data, t_map *map);

#endif