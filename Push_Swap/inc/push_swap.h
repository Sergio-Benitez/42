/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:09:02 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/13 19:34:36 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/inc/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	int				target_pos;
	struct s_node	*next;
}					t_node;

		//		CHECK_ARGS.C	//
		
int	ft_check_args(char **argv, t_node **stack_a);

		//		LST_UTILS.C		//
		
t_node *ft_newnode(int value);
void	ft_pushnode(t_node **stack, int value);

#endif