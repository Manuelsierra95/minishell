/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:06 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/12 19:14:57 by mbarylak         ###   ########.fr       */
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
/*
struct	builtin_t
{
	char *builtin;
	int	(*f)();
}

{
	bultin_t	array[8];

	array[1].builtin =  
	array[1].f = 
}

int i = 0;
while (i < 8)
{
	if (array[i].builtin == cmd)
		array[i].f;
	i++;
}*/

void	ft_pipex_s(int n, char **argv, t_pipex *pipex)
{
	int	pid;
	int	fd[2];

	if(g_shell->swicth)

	if (pipe(fd) == -1)
		ft_error("pipex", 0);
	pid = fork();
	if (pid == -1)
		ft_error("pipex", 0);
	if (pid == 0)
	{
		close(fd[READ_END]);
		if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
			ft_error("pipex", 0);
		close(fd[WRITE_END]);
		ft_exe(argv, n, pipex);
	}
	else
		ft_pipex_p(fd, pid);
}
