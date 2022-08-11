/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:05:20 by mbarylak          #+#    #+#             */
/*   Updated: 2022/08/11 20:16:58 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*check_redir(t_redir *redir)
{
	int	*fd;

	fd = malloc(2 * sizeof (int));
	fd[0] = 0;
	fd[1] = 1;
	if (redir->r_type == REDIR_OUT)
		fd[1] = open(redir->value, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (redir->r_type == REDIR_IN)
		fd[0] = open(redir->value, O_RDONLY, 0777);
	else if (redir->r_type == REDIR_APPEND)
		fd[1] = open(redir->value, O_APPEND | O_WRONLY | O_CREAT, 0777);
	//else if (here_doc)
	return (fd);
}

void	redir_loop(t_tree *tree)
{
	t_redir	*a_redir;
	int		*fd;
	int		std_fd[2];

	a_redir = tree->l_redir;
	std_fd[0] = dup(STDIN_FILENO);
	std_fd[1] = dup(STDOUT_FILENO);
	if (a_redir)
	{
		while (a_redir->next)
		{
			check_redir(a_redir);
			a_redir = a_redir->next;
		}
		fd = check_redir(a_redir);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		exe_single_child(tree, 1);
	}
	else
		exe_single_child(tree, 1);
	dup2(std_fd[0], STDIN_FILENO);
	dup2(std_fd[1], STDOUT_FILENO);
	close(std_fd[0]);
	close(std_fd[1]);
}
