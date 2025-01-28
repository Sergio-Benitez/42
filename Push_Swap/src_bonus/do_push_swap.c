/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:09:54 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/28 20:36:48 by sbenitez         ###   ########.fr       */
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

int	ft_execute_instruction(t_node **stack_a, t_node **stack_b, char *instruct)
{
	if (ft_strncmp(instruct, "sa", 2) == 0)
		ft_sa(stack_a);
	else if (ft_strncmp(instruct, "sb", 2) == 0)
		ft_sb(stack_b);
	else if (ft_strncmp(instruct, "pa", 2) == 0)
		ft_pa(stack_a, stack_b);
	else if (ft_strncmp(instruct, "pb", 2) == 0)
		ft_pb(stack_a, stack_b);
	else if (ft_strncmp(instruct, "ra", 2) == 0)
		ft_ra(stack_a);
	else if (ft_strncmp(instruct, "rb", 2) == 0)
		ft_rb(stack_b);
	else if (ft_strncmp(instruct, "rra", 3) == 0)
		ft_rra(stack_a);
	else if (ft_strncmp(instruct, "rrb", 3) == 0)
		ft_rrb(stack_b);
	else if (ft_strncmp(instruct, "rrr", 3) == 0)
		ft_rrr(stack_a, stack_b);
	else if (ft_strncmp(instruct, "rr", 2) == 0)
		ft_rr(stack_a, stack_b);
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
		if (!ft_execute_instruction(stack_a, stack_b, instruct[i]))
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
