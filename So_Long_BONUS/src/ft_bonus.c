/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:44:07 by sbenitez          #+#    #+#             */
/*   Updated: 2024/11/11 13:14:20 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void	ft_moves(t_game *game)
{
	char	*mov;

	if (game->wmoves)
		mlx_delete_image(game->mlx, game->wmoves);
	mov = ft_itoa(game->move_count);
	mov = ft_strjoin("Movements: ", mov);
	game->wmoves = mlx_put_string(game->mlx, mov, 16, 16);
	free (mov);
}
