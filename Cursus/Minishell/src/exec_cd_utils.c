/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:16:39 by sbenitez          #+#    #+#             */
/*   Updated: 2025/05/29 20:26:04 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_check_errors(t_shell *shell, char *oldpwd, char *path)
{
	if (!oldpwd)
	{
		ft_putstr_fd("minishell: cd: error retrieving current directory: ", 2);
		ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
		shell->exit_status = 1;
		return (1);
	}
	if (chdir(path) < 0)
	{
		perror("minishell: cd");
		free(oldpwd);
		shell->exit_status = 1;
		return (1);
	}
	return (0);
}

int	ft_update_pwd(t_shell *shell, char *oldpwd, char *pwd)
{
	char	*aux;

	aux = ft_strjoin("OLDPWD=", oldpwd);
	if (!aux)
		return (1);
	shell->env = ft_add_modify_env(shell->env, aux, 1);
	free(aux);
	aux = ft_strjoin("PWD=", pwd);
	if (!aux)
		return (1);
	shell->env = ft_add_modify_env(shell->env, aux, 1);
	free(aux);
	return (0);
}

int	ft_check_home_error(t_shell *shell, char *home, char *oldpwd)
{
	perror("minishell: cd");
	free(oldpwd);
	free(home);
	shell->exit_status = 1;
	return (1);
}

void	ft_update_home(t_shell *shell, char *oldpwd, char *pwd)
{
	char	*pwd_var;
	char	*oldpwd_var;

	if (oldpwd)
	{
		oldpwd_var = ft_strjoin("OLDPWD=", oldpwd);
		ft_add_modify_env(shell->env, oldpwd_var, 1);
		free(oldpwd_var);
	}
	pwd_var = ft_strjoin("PWD=", pwd);
	ft_add_modify_env(shell->env, pwd_var, 1);
	free(pwd_var);
}
