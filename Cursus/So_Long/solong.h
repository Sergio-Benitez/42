/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:29 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/09 13:32:41 by sbenitez         ###   ########.fr       */
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

# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	int			x;
	int			y;
}				t_map;

char	**load_create_map(char *file);

#endif