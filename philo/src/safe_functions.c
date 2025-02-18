/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:31:02 by sbenitez          #+#    #+#             */
/*   Updated: 2025/02/18 17:31:19 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;
	ret = malloc(bytes);
	if (!ret)
		ft_exit_error("Error with the malloc");
	return(ret);
}