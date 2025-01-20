/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:09:02 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/20 19:25:49 by sbenitez         ###   ########.fr       */
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
int			ft_check_limits(long long *llong_array, int size);
int			ft_check_dups(long long *values, int size);
long long	*ft_check_args(char **argv, int *size);

		//		FREE_FUNCTIONS.C	//

void		ft_free_matrix(char **matrix);
void		ft_free_stack(t_node **stack);
void		ft_free_exit(t_node **stack_a, t_node **stack_b, long long *array);

		//		LST_UTILS.C			//

t_node		*ft_newnode(int value);
void		ft_pushnode(t_node **stack, int value);
void		ft_recalculate(t_node **stack);
void		ft_get_stacksize(t_node **stack);

		//		LST_UTILS2.C		//

void		ft_sort_three(t_node **stack);

		//			MAIN.C			//

void		ft_print_stack(t_node *stack);
void		ft_init(t_node **stack_a, int size, long long **llong_array);

		//		OPERATIONS.C		//

void		ft_pa(t_node **stack_a, t_node **stack_b);
void		ft_pb(t_node **stack_a, t_node **stack_b);
void		ft_ra(t_node **stack_a, int flag);
void		ft_rb(t_node **stack_b, int flag);
void		ft_rr(t_node **stack_a, t_node **stack_b);

		//		OPERATIONS2.C		//

void		ft_sa(t_node **stack_a);
void		ft_sb(t_node **stack_b);
void		ft_rra(t_node **stack_a, int flag);
void		ft_rrb(t_node **stack_b, int flag);
void		ft_rrr(t_node **stack_a, t_node **stack_b);

		//			UTILS.C			//

long long	ft_atoll(const char *str);
long long	*ft_llongize_args(char **clean_args, int size);
int			ft_sort_llongtab(long long *tab, int size);
void		ft_get_index(long long *tab, t_node **stack_a, int size);
void		ft_getpos(t_node **stack);

#endif