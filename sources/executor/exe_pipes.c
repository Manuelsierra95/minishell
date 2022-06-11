/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:54:42 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/11 12:07:13 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	choose_exec(t_tree *tree, t_shell *shell, int fd)
// {
// 	if (is_builtin(tree->cmd[0]))
// 		exec_builtin(tree->cmd, shell, fd);
// 	else
// 		exe_cmd(tree->cmd, shell);
// }

void	choose_exec(t_tree *tree, t_shell *shell, int fd)//Quizas no hay falta pasarle la shell
{
	t_value		*exec;
	void		*get_arg;

	g_shell->arg = tree->cmd;
	g_shell->fd = fd;//Da fallo con tu fd
	if (get(g_shell->map, tree->cmd[0]))
	{
		printf("Ejecuta el builtin\n");
		exec = get(g_shell->map, tree->cmd[0]);
		get_arg = exec->get_arg();
		exec->function(get_arg);
		free(get_arg);	// Ejecutar despues de cada exec
	}
	else
		exe_cmd(tree->cmd, shell);
}

void	first_child(t_tree *tree, t_shell *shell)
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
		choose_exec(tree, shell, fd[1]);
	}
	else
	{
		shell->oldfd[0] = fd[0];
		shell->oldfd[1] = fd[1];
		close(fd[1]);
		waitpid(pid, &status, 0);
	}
}

void	middle_child(t_tree *tree, t_shell *shell)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(shell->oldfd[0], STDIN_FILENO);
		close(shell->oldfd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		choose_exec(tree, shell, fd[1]);
	}
	else
	{
		close(shell->oldfd[0]);
		shell->oldfd[0] = fd[0];
		shell->oldfd[1] = fd[1];
		close(fd[1]);
		waitpid(pid, &status, 0);
	}
}

void	last_child(t_tree *tree, t_shell *shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		dup2(shell->oldfd[0], STDIN_FILENO);
		close(shell->oldfd[0]);
		choose_exec(tree, shell, 1);
	}
	else
	{
		close(shell->oldfd[0]);
		waitpid(pid, &status, 0);
	}
}

int	exe_pipes(t_tree *tree, t_shell *shell)
{
	if (tree->pos_cmd == P_FIRST)
		first_child(tree, shell);
	else if (tree->pos_cmd == P_MIDDLE)
		middle_child(tree, shell);
	else if (tree->pos_cmd == P_LAST)
		last_child(tree, shell);
	else if (tree->pos_cmd == 0)
		return (0);
	return (0);
}
