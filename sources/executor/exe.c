/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:06 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/01 18:28:51 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_single_child(char **cmd, t_shell *shell, int fd)
{
	int	pid;
	int	status;
	int	ret;

	ret = 1;
	if (is_builtin(cmd[0]))
		return (exec_builtin(cmd, shell, fd));
	else
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{	
			ret = exe_cmd(cmd, shell);
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
	return (ret);
}

int	exec(t_exec *exe, t_shell *shell)
{
	int	ret;

	ret = 1;
	if (shell->pipes == 0)
		ret = exe_single_child(exe->cmds->arg, shell, 1);
	else
	{
		ret = exe_pipes(exe, shell);
		shell->pipes = 0;
	}
	return (ret);
}
