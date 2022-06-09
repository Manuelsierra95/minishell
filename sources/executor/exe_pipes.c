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

static void	choose_exec(t_tree *tree, t_shell *shell, int fd)
{
	if (is_builtin(tree->cmd[0]))
		exec_builtin(tree->cmd, shell, fd);
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
	t_tree	*tree_aux;

	tree_aux = tree;
	while (tree_aux)
	{
		if (tree_aux->left == NULL)
			first_child(tree_aux, shell);
		else if (tree_aux->left && tree_aux->right)
			middle_child(tree_aux, shell);
		else if (tree_aux->right == NULL)
			last_child(tree_aux, shell);
		tree_aux = tree_aux->right;
	}
	return (0);
}
