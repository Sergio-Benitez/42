/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/10 01:51:37 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef MAX_WIDTH
#  define MAX_WIDTH	15
# endif

# ifndef MAX_HEIGHT
#  define MAX_HEIGHT	15
# endif

# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	int			width;
	int			height;
	char		**data;
}				t_map;

char	**load_create_map(char *file);
t_map	*get_struct(char **map_data);
int		check_map(t_map *map);
int		check_extension(char *name);
int		check_frame(t_map *map);
int		check_chars(t_map *map);

#endif