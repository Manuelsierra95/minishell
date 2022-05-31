/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:50:37 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/31 18:41:41 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	t_cmd	*aux;

	aux = cmd;
	//print_env(cmd->arg);
	while (aux)
		aux = aux->next;
	return (aux);
}
/*
t_cmds *add_cmds(char *arg, t_cmd *cmd, int i)
{
	t_cmd	*new;
	t_cmd	*last;

	if (!cmd)
		last = NULL;
	else
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
}*/

t_cmd	*create_node(char *cmd)
{
	t_cmd	*new;

	new = malloc(sizeof (t_cmd));
	new->arg = ft_split(cmd, ' ');
	new->next = NULL;
	//new->prev = last;
	return (new);
}

void	add_node_back(char *cmd, t_cmd **cmds)
{
	t_cmd	*last;
	t_cmd	*new;

	last = ft_cmdlast(*cmds);
	printf("Last: \n");
	print_env(last->arg);
	printf("\n");
	new = create_node(cmd);
	printf("New: \n");
	print_env(new->arg);
	printf("\n");
	new->prev = last;
	last->next = new;
}

void	add_cmds(char *cmd, t_cmd **cmds)
{
	if (!*cmds)
	{
		dprintf(2, "Hola\n");
		*cmds = create_node(cmd);
	}
	else
		add_node_back(cmd, cmds);
}
/* Dividir add_cmds en dos funciones: create new node and add node back */
