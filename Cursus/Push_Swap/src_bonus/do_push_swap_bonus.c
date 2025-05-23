/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:09:54 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/30 12:45:02 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size - sizeof(char *));
	free(ptr);
	return (new_ptr);
}

char	**ft_read_instructions(void)
{
	char	*line;
	char	**instructions;
	int		i;

	i = 0;
	instructions = NULL;
	while (1)
	{
		instructions = ft_realloc(instructions, sizeof(char *) * (i + 1));
		line = get_next_line(0);
		if (!line)
			break ;
		instructions[i] = line;
		i++;
	}
	instructions[i] = NULL;
	return (instructions);
}

int	ft_exec_instruct(t_node **a, t_node **b, char *instruct)
{
	if (ft_strncmp(instruct, "sa", 2) == 0)
		ft_sa(a);
	else if (ft_strncmp(instruct, "sb", 2) == 0)
		ft_sb(b);
	else if (ft_strncmp(instruct, "ss", 2) == 0)
		return (1);
	else if (ft_strncmp(instruct, "pa", 2) == 0)
		ft_pa(a, b);
	else if (ft_strncmp(instruct, "pb", 2) == 0)
		ft_pb(a, b);
	else if (ft_strncmp(instruct, "ra", 2) == 0)
		ft_ra(a);
	else if (ft_strncmp(instruct, "rb", 2) == 0)
		ft_rb(b);
	else if (ft_strncmp(instruct, "rra", 3) == 0)
		ft_rra(a);
	else if (ft_strncmp(instruct, "rrb", 3) == 0)
		ft_rrb(b);
	else if (ft_strncmp(instruct, "rrr", 3) == 0)
		ft_rrr(a, b);
	else if (ft_strncmp(instruct, "rr", 2) == 0)
		ft_rr(a, b);
	else
		return (0);
	return (1);
}

void	ft_do_pushswap(t_node **stack_a, t_node **stack_b, char **instruct)
{
	int	i;

	i = 0;
	while (instruct[i])
	{
		if (!ft_exec_instruct(stack_a, stack_b, instruct[i]))
		{
			ft_putendl_fd("Error", 2);
			ft_free_ssi(stack_a, stack_b, instruct);
		}
		i++;
	}
	ft_free_matrix(instruct, 1);
}

void	ft_check_result(t_node *stack_a, t_node *stack_b)
{
	if (ft_is_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
