/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:10:34 by sbenitez          #+#    #+#             */
/*   Updated: 2024/05/30 22:52:43 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	printstr(char *str, int *count)
{
	int	i;
	
	i = 0;
	while(str[i])
		printchar(str[i++]);
	return (count + i);
}