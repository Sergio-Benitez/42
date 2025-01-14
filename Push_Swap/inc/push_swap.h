/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:09:02 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/14 19:55:43 by sbenitez         ###   ########.fr       */
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
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

		//		CHECK_ARGS.C	//

char		**ft_clean_quote(char **argv);
int			ft_check_int(char **clean_args);
int			ft_check_limits(long long *llong_array);
int			ft_check_dups(long long *values, int size);
int			ft_check_args(char **argv, t_node **stack_a);

		//		LST_UTILS.C		//

t_node		*ft_newnode(int value);
void		ft_pushnode(t_node **stack, int value);

		//			UTILS.C		//

long long	ft_atoll(const char *str);
long long	*ft_llongize_args(char **clean_args, int size);

#endif