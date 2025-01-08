/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:09:13 by sbenitez          #+#    #+#             */
/*   Updated: 2024/06/29 17:49:36 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
void	printchar(int c, int *count);
void	printstr(char *str, int *count);
void	check_ptr(void *ptr, int *count);
void	printint(int n, int *count);
void	printuns(unsigned int n, int *count);
void	printhex(unsigned int n, const char x, int *count);

#endif