/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:50:37 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/23 17:42:41 by mbarylak         ###   ########.fr       */
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
	{	
		new->prev = NULL;
		cmd = new;
	}
	else
	last->next = new;
	return (cmd);
}
