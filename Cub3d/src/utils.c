/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:00:00 by sbenitez          #+#    #+#             */
/*   Updated: 2025/09/19 11:59:40 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

uint32_t	ft_get_color_from_rgb(int r, int g, int b)
{
	return ((r << 24) + (g << 16) + (b << 8) + 255);
}

char	**ft_split_and_trim(char *str, char delimiter)
{
	char	**split;
	char	*trimmed;
	int		i;

	split = ft_split(str, delimiter);
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		trimmed = ft_strtrim(split[i], " \t\n\r");
		free(split[i]);
		split[i] = trimmed;
		if (!split[i])
		{
			ft_free_split(split);
			return (NULL);
		}
		i++;
	}
	return (split);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
