/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:14:15 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/08 13:10:52 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		ft_memdel(arr);
}

void	free_env(t_list *env)
{
	t_list	*aux;

	while (env && env->next)
	{
		aux = env;
		env = env->next;
		ft_memdel(aux->content);
		ft_memdel(aux);
	}
	ft_memdel(env->content);
	ft_memdel(env);
}

// void	free_cmds(t_cmd	*cmd)
// {
// 	t_cmd	*aux;
// 	t_cmd	*node;

// 	aux = cmd;
// 	while (aux)
// 	{
// 		node = aux;
// 		aux = aux->next;
// 		free_arr(node->arg);
// 		ft_memdel(node);
// 	}
// }
