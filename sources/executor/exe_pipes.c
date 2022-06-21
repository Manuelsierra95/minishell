/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:54:42 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/21 16:38:16 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	choose_exec(t_tree *tree, int fd)//Quizas no hay falta pasarle la shell
{
	t_value		*exec;
	void		*get_arg;

	g_shell->arg = tree->cmd;
	g_shell->fd[1] = fd;
	if (get(g_shell->map, tree->cmd[0]))
	{
		exec = get(g_shell->map, tree->cmd[0]);
		get_arg = exec->get_arg();
		exec->function(get_arg);
		free(get_arg);
	}
	else
		exe_cmd(tree->cmd, g_shell);
}

void	first_child(t_tree *tree)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		choose_exec(tree, fd[1]);
	}
	else
	{
		g_shell->oldfd[0] = fd[0];
		g_shell->oldfd[1] = fd[1];
		close(fd[1]);
	}
}

void	middle_child(t_tree *tree)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(g_shell->oldfd[0], STDIN_FILENO);
		close(g_shell->oldfd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		choose_exec(tree, fd[1]);
	}
	else
	{
		close(g_shell->oldfd[0]);
		g_shell->oldfd[0] = fd[0];
		g_shell->oldfd[1] = fd[1];
		close(fd[1]);
	}
}

void	last_child(t_tree *tree)
{
	int	pid;
	int	status;
	int	x;	

	x = 1;
	pid = fork();
	if (pid == 0)
	{
		dup2(g_shell->oldfd[0], STDIN_FILENO);
		close(g_shell->oldfd[0]);
		choose_exec(tree, 1);
	}
	else
	{
		close(g_shell->oldfd[0]);
		waitpid(pid, &status, 0);
		while (x != -1)
			x = wait(&status);
	}
}

int	exe_pipes(t_tree *tree)
{
	if (tree->pos_cmd == P_FIRST)
		first_child(tree);
	else if (tree->pos_cmd == P_MIDDLE)
		middle_child(tree);
	else if (tree->pos_cmd == P_LAST)
		last_child(tree);
	else if (tree->pos_cmd == 0)
		return (0);
	return (0);
}
