/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:06 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/21 19:04:05 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_status(int status)
{
	if (WIFEXITED(status))
		g_shell->exit_stat = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_shell->exit_stat = WTERMSIG(status);
	else if (WIFSTOPPED(status))
		g_shell->exit_stat = WSTOPSIG(status);
	else
		g_shell->exit_stat = 0;
}

int	exe_single_child(t_tree *tree, int fd)
{
	int		pid;
	int		status;
	t_value	*exec;
	void	*get_arg;
	int		ret;

	g_shell->arg = tree->cmd;
	g_shell->fd[1] = fd;
	if (get(g_shell->map, tree->cmd[0]))
	{
		exec = get(g_shell->map, tree->cmd[0]);
		get_arg = exec->get_arg();
		g_shell->exit_stat = (int ) exec->function(get_arg);
		free(get_arg);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{	
			ret = exe_cmd(tree->cmd, g_shell);
			exit(ret);
		}
		else
		{	
			waitpid(pid, &status, 0);
			exit_status(status);
		}
	}
	dprintf(2, "exit_status: %d\n", g_shell->exit_stat);
	return (0);
}
