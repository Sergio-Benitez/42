/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:34:27 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/30 14:18:01 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_redir_heredoc(t_shell *shell, t_cmd *cmd)
{
	int		pipefd[2];
	char	*buffer;

	g_signal_flag = 2;
	if (pipe(pipefd) == -1)
		return (perror("Error pipe\n"), 1);
	while (1)
	{
		buffer = readline("> ");
		if (!buffer || !ft_strcmp(buffer, cmd->delimiter))
		{
			free(buffer);
			break ;
		}
		buffer = ft_expand_heredoc(buffer, shell->env, shell->last_exit_st);
		write(pipefd[1], buffer, ft_strlen(buffer));
		write(pipefd[1], "\n", 1);
		free(buffer);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (perror("Error heredoc\n"), 1);
	return (close(pipefd[0]), 0);
}

int	ft_redir_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Error duplicating input file\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_redir_outfile(char *outfile, int append)
{
	int	fd;

	if (append == 1)
		fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error duplicating output file\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_redirections(t_shell *shell, t_cmd *cmd)
{
	if (cmd->hd && ft_redir_heredoc(shell, cmd))
		return (1);
	if (!cmd->hd && cmd->infile && ft_redir_infile(cmd->infile))
		return (1);
	if (cmd->outfile && ft_redir_outfile(cmd->outfile, cmd->append))
		return (1);
	return (0);
}
