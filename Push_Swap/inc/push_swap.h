/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:09:02 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/15 14:05:38 by sbenitez         ###   ########.fr       */
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
	int				size;
	struct s_node	*next;
}	t_node;

		//		CHECK_ARGS.C		//

char		**ft_clean_quote(char **argv);
int			ft_check_int(char **clean_args);
int			ft_check_limits(long long *llong_array);
int			ft_check_dups(long long *values, int size);
long long	*ft_check_args(char **argv, int *size);

		//		FREE_FUNCTIONS.C	//

void		ft_free_matrix(char **matrix);

		//		LST_UTILS.C			//

t_node		*ft_newnode(int value);
void		ft_pushnode(t_node **stack, int value);

		//			MAIN.C			//

void		ft_print_stack(t_node *stack);

		//			UTILS.C			//

long long	ft_atoll(const char *str);
long long	*ft_llongize_args(char **clean_args, int size);
void		ft_sort_llongtab(long long *tab, int size);
void		ft_get_index(long long *tab, t_node **stack_a, int size);

#endif