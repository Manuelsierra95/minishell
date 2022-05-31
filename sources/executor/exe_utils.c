/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:50:37 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/31 19:34:17 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	t_cmd	*aux;

	aux = cmd;
	while (aux->next)
		aux = aux->next;
	return (aux);
}

t_cmd	*create_node(char *cmd)
{
	t_cmd	*new;

	new = malloc(sizeof (t_cmd));
	new->arg = ft_split(cmd, ' ');
	new->next = NULL;
	return (new);
}

void	add_node_back(char *cmd, t_cmd **cmds)
{
	t_cmd	*last;
	t_cmd	*new;

	last = ft_cmdlast(*cmds);
	new = create_node(cmd);
	new->prev = last;
	last->next = new;
}

void	add_cmds(char *cmd, t_cmd **cmds)
{
	if (!*cmds)
		*cmds = create_node(cmd);
	else
		add_node_back(cmd, cmds);
}
