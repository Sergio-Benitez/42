/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:07 by sbenitez          #+#    #+#             */
/*   Updated: 2024/08/21 13:57:26 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != '\0')
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}