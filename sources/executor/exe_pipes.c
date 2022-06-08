/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:54:42 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/01 19:26:15 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	choose_exec(t_cmd *cmds, t_shell *shell, int fd)
{
	if (is_builtin(cmds->arg[0]))
		exec_builtin(cmds->arg, shell, fd);
	else
		exe_cmd(cmds->arg, shell);
}

void	first_child(t_exec *exe, t_cmd *cmds, t_shell *shell)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		choose_exec(cmds, shell, fd[1]);
	}
	else
	{
		exe->oldfd[0] = fd[0];
		exe->oldfd[1] = fd[1];
		close(fd[1]);
		waitpid(pid, &status, 0);
	}
}

void	middle_child(t_exec *exe, t_cmd *cmds, t_shell *shell)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(exe->oldfd[0], STDIN_FILENO);
		close(exe->oldfd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		choose_exec(cmds, shell, fd[1]);
	}
	else
	{
		close(exe->oldfd[0]);
		exe->oldfd[0] = fd[0];
		exe->oldfd[1] = fd[1];
		close(fd[1]);
		waitpid(pid, &status, 0);
	}
}

void	last_child(t_exec *exe, t_cmd *cmds, t_shell *shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		dup2(exe->oldfd[0], STDIN_FILENO);
		close(exe->oldfd[0]);
		choose_exec(cmds, shell, 1);
	}
	else
	{
		close(exe->oldfd[0]);
		waitpid(pid, &status, 0);
	}
}

int	exe_pipes(t_exec *exe, t_shell *shell)
{
	t_cmd	*cmd_node;

	cmd_node = exe->cmds;
	while (cmd_node)
	{
		if (cmd_node->prev == NULL)
			first_child(exe, cmd_node, shell);
		else if (cmd_node->prev && cmd_node->next)
			middle_child(exe, cmd_node, shell);
		else if (cmd_node->next == NULL)
			last_child(exe, cmd_node, shell);
		cmd_node = cmd_node->next;
	}
	return (0);
}
