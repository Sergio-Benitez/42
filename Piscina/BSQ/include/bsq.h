/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labderra <labderra@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:38:03 by labderra          #+#    #+#             */
/*   Updated: 2024/03/21 13:55:43 by labderra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

struct	s_map
{
	char	*board;
	char	c_free;
	char	c_obst;
	char	c_full;
	int		n_lines;
	int		line_len;
};

char			*ft_keyb_entry(void);

struct s_map	ft_map(char *str);

void			ft_error(char *str);

int				ft_strlen(char *str);

char			*ft_strclip(char *dest, char *src, int nb);

char			*ft_strtrim(char *src, int nb);

int				ft_atoi(char *str);

int				ft_file_size(char *str, int *n_lines);

int				ft_file_load(char *str, char *map);

struct s_map	ft_solve(struct s_map map);

#endif
