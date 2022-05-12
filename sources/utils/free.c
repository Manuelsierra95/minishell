/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:14:15 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/12 19:50:10 by mbarylak         ###   ########.fr       */
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
			ft_memdel(arr[i]);
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
