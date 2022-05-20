/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:12:54 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/20 17:04:33 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

int	exec_builtin(char **cmd, t_shell *shell, int fd)
{
	int	ret;

	ret = 1;
	if (ft_strcmp(cmd[0], "pwd") == 0)
		ret = ft_pwd(fd);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		ret = ft_echo(fd, cmd);
	else if (ft_strcmp(cmd[0], "export") == 0)
		ret = ft_export(cmd, shell->env, shell->secret, fd);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		ret = ft_unset(cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ret = ft_cd(cmd, shell->env);
	else if (ft_strcmp(cmd[0], "env") == 0)
		ret = ft_env(shell->env, fd);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd, &shell);
	return (ret);
}
