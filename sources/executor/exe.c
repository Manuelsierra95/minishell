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

// int	exe_single_child(char **cmd, t_shell *shell, int fd)
// {
// 	int	pid;
// 	int	status;
// 	int	ret;

// 	ret = 1;
// 	if (is_builtin(cmd[0]))
// 		return (exec_builtin(cmd, shell, fd));
// 	else
// 	{
// 		pid = fork();
// 		if (pid == -1)
// 			return (-1);
// 		else if (pid == 0)
// 		{	
// 			ret = exe_cmd(cmd, shell);
// 			exit(EXIT_FAILURE);
// 		}
// 		else
// 			waitpid(pid, &status, 0);
// 	}
// 	return (ret);
// }

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
// 	return (ret);
// }
