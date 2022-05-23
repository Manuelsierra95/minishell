/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:54:42 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/23 18:57:34 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_child(t_exec *exe, t_shell *shell)
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
		if (is_builtin(exe->cmds->arg[0]))
			exec_builtin(exe->cmds->arg, shell, fd[1]);
		else
			exe_cmd(exe->cmds->arg, shell);
	}
	else
	{
		exe->oldfd_in = fd[0];
		exe->oldfd_out = fd[1];
		close(fd[1]);
		waitpid(pid, &status, 0);
	}
}

void	middle_child(t_exec *exe, t_shell *shell)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(exe->oldfd_in, STDIN_FILENO);
		close(exe->oldfd_in);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (is_builtin(exe->cmds->arg[0]))
			exec_builtin(exe->cmds->arg, shell, fd[1]);
		else
			exe_cmd(exe->cmds->arg, shell);
	}
	else
	{
		close(exe->oldfd_in);
		exe->oldfd_in = fd[0];
		exe->oldfd_out = fd[1];
		close(fd[1]);
		waitpid(pid, &status, 0);
	}
}

void	last_child(t_exec *exe, t_shell *shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		dup2(exe->oldfd_in, STDIN_FILENO);
		close(exe->oldfd_in);
		if (is_builtin(exe->cmds->arg[0]))
			exec_builtin(exe->cmds->arg, shell, 1);
		else
			exe_cmd(exe->cmds->arg, shell);
	}
	else
	{
		close(exe->oldfd_in);
		waitpid(pid, &status, 0);
	}
}

int	exe_pipes(t_exec *exe, t_shell *shell)
{
	while (exe->cmds)
	{
		if (exe->cmds->prev == NULL)
			first_child(exe, shell);
		else if (exe->cmds->prev && exe->cmds->next)
			middle_child(exe, shell);
		else if (exe->cmds->next == NULL)
			last_child(exe, shell);
		exe->cmds = exe->cmds->next;
	}
	return (0);
}
