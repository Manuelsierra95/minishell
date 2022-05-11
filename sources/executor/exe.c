/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:06 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/11 17:35:44 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_child(char **cmd, t_shell *shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{	
		exe_cmd(cmd, shell);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}
