/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:54:33 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/28 14:39:02 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_exit_error(char *error)
{
	printf("%s\n", error);
	exit (EXIT_FAILURE);
}

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		ft_exit_error("minishell: Memory allocation error");
	return (ret);
}

void	ft_print_tokens(t_token *token)
{
	while (token)
	{
		printf("Token: [%s]\t", token->tkn);
		printf("Type: [%i]\n", token->type);
		token = token->next;
	}
}

char	**ft_copy_env(char **env)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	while (env[i])
		i++;
	cpy = safe_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		cpy[i] = safe_malloc(sizeof (char) * (ft_strlen(env[i]) + 1));
		j = 0;
		while (env[i][j])
		{
			cpy[i][j] = env[i][j];
			j++;
		}
		cpy[i][j] = '\0';
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	ft_print_cmdlst(t_cmd *cmd_lst)
{
	int	i;

	while (cmd_lst)
	{
		i = 0;
		printf("\n  Args: ");
		if (cmd_lst->args)
		{
			while (cmd_lst->args[i])
				printf("[%s], ", cmd_lst->args[i++]);
		}
		else
			printf("[NULL]");
		if (cmd_lst->infile)
			printf("\n  Infile: %s", cmd_lst->infile);
		if (cmd_lst->outfile)
			printf("\n  Outfile: %s", cmd_lst->outfile);
		if (cmd_lst->delimiter)
			printf("\n  Delimiter: %s", cmd_lst->delimiter);
		printf("\n  Append: %d", cmd_lst->append);
		printf("\n  Heredoc: %d", cmd_lst->hd);
		printf("\n  Is Built-in: %d\n", cmd_lst->is_btn);
		cmd_lst = cmd_lst->next;
	}
}
