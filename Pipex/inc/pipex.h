/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:19:47 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/11 16:36:56 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/inc/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

				//	PROCESS_PATH.C	//

void	child(int *pipefd, char **argv, char **env);
void	parent(int *pipefd, char **argv, char **env);
char	*find_path(char *str, char **env, int len);
char	**split_path(char *path, int start);
char	*check_access(char **path_list, char *cmd);

				// 		MAIN.C		//

void	free_split(char **array);
void	ft_exit_error(char *str);
void	run_cmd(char *argv, char **env);
int		handle_child_exit(pid_t pid);

#endif