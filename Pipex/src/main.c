/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:01 by sbenitez          #+#    #+#             */
/*   Updated: 2025/01/08 20:49:22 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char** env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(1, "The argument number must be 5", 29);
		exit(1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("Pipe error");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	if (pid == 0)
	{
		// child proseso
		close(pipefd[0]);
	}
	else
	{
		// parent proseso
		close(pipefd[0]);
	}
	return (0);
}