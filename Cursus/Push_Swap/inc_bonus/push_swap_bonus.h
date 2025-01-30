/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:04:44 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/29 20:38:30 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../Libft/inc/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				size;
	struct s_node	*next;
}	t_node;

		//		CHECK_ARGS.C		//

char		**ft_clean_quote(char **argv);
int			ft_check_int(char **clean_args);
int			ft_check_limits(long long *llong_array, int size);
int			ft_check_dups(long long *values, int size);
long long	*ft_check_args(char **argv, int *size);

		//		DO_PUSH_SWAP.C		//

void		*ft_realloc(void *ptr, size_t new_size);
char		**ft_read_instructions(void);
int			ft_exec_instruct(t_node **a, t_node **b, char *instruct);
void		ft_do_pushswap(t_node **stack_a, t_node **stack_b, char **instruct);
void		ft_check_result(t_node *stack_a, t_node *stack_b);

		//		FREE_FUNCTIONS.C	//

void		ft_free_llongarray(long long *array, int flag);
void		ft_free_matrix(char **matrix, int flag);
void		ft_free_stack(t_node **stack);
void		ft_free_exit(t_node **stack_a, t_node **stack_b, long long *array);
void		ft_free_ssi(t_node **a, t_node **b, char **i);

		//			FT_MOVE.C		//

void		ft_do_rrr(t_node **stack_a, t_node **stack_b,
				int *cost_a, int *cost_b);
void		ft_do_rr(t_node **stack_a, t_node **stack_b,
				int *cost_a, int *cost_b);
void		ft_do_ra(t_node **stack_a, int *cost);
void		ft_do_rb(t_node **stack_b, int *cost);

		//		LST_UTILS.C			//

t_node		*ft_newnode(int value);
void		ft_pushnode(t_node **stack, int value);
int			ft_is_sorted(t_node *stack);
void		ft_get_stacksize(t_node **stack);

		//			MAIN.C			//

void		ft_init(t_node **stack_a, int size, long long **llong_array);

		//		OPERATIONS.C		//

void		ft_pa(t_node **stack_a, t_node **stack_b);
void		ft_pb(t_node **stack_a, t_node **stack_b);
void		ft_ra(t_node **stack_a);
void		ft_rb(t_node **stack_b);
void		ft_rr(t_node **stack_a, t_node **stack_b);

		//		OPERATIONS2.C		//

void		ft_sa(t_node **stack_a);
void		ft_sb(t_node **stack_b);
void		ft_rra(t_node **stack_a);
void		ft_rrb(t_node **stack_b);
void		ft_rrr(t_node **stack_a, t_node **stack_b);

		//			UTILS.C			//

long long	ft_atoll(const char *str);
long long	*ft_llongize_args(char **clean_args, int size);

#endif