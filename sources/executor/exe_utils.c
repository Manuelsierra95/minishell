/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:50:37 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/18 21:02:27 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

t_cmd	*ft_cmdfirst(t_cmd	*cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}

void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	if (!cmd)
		return ;
	if (*cmd == NULL)
	{
		printf("OK1\n");
		*cmd = new;
	}
	else
		ft_cmdlast(*cmd)->next = new;
}

t_cmd	*add_cmds(char *arg, t_cmd *cmd, int i)
{
	t_cmd	*new;
	t_cmd	*last;

	last = ft_cmdlast(cmd);
	new = malloc(sizeof (t_cmd));
	if (!new)
		return (NULL);
	new->arg = ft_split(arg, ' ');
	new->next = NULL;
	new->prev = last;
	if (i == 0)
		cmd = new;
	else
		last->next = new;
	return (cmd);
}
