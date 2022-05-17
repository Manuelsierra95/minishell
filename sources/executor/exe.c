/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:06 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/17 21:20:39 by mbarylak         ###   ########.fr       */
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

t_cmd	*add_cmds(char **arg, t_cmd	*cmds)
{
	t_cmd	*last;
	t_cmd	*first;
	t_cmd	*new;

	first = cmds;
	last = ft_lstlast(cmds);
	new = malloc(sizeof (t_cmd));
	if (!new)
		return (NULL);
	new->arg = arg;
	new->prev = last;
	new->next = NULL;
		
}
