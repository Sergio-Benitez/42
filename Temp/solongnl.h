/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongnl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:41:06 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/06 20:01:04 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef MAX_WIDTH
#  define MAX_WIDTH	15
# endif

# ifndef MAX_HEIGHT
#  define MAX_HEIGHT	15
# endif

# include "GetNextLine/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

char	**load_create_map(char *file);

#endif