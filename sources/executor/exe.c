/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:06 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/09 12:06:21 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_single_child(t_tree *tree, int fd)
{
 	int		pid;
 	int		status;
	t_value	*exec;
	void	*get_arg;

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
 	{
 		pid = fork();
 		if (pid == -1)
 			return (-1);
 		else if (pid == 0)
 		{	
 			exe_cmd(tree->cmd, g_shell);
 			exit(EXIT_FAILURE);
 		}
 		else
 			waitpid(pid, &status, 0);
 	}
	return (0);
}

// int	exec(t_tree *tree, t_shell *shell)
// {
// 	int	ret;

// 	ret = 1;
// 	if (shell->numOfPipes == 0)
// 		ret = exe_single_child(tree->cmd, shell, 1);
// 	else
// 	{
// 		ret = exe_pipes(tree, shell);
// 		shell->numOfPipes = 0;
// 	}
// 	0return (ret);
// }
