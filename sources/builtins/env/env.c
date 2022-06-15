/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:52:19 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 17:21:42 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	env_to_shell(char **env_arr)
{
	t_list	*env;
	t_list	*new;
	int		i;

	env = malloc(sizeof (t_list));
	if (!env)
		return (1);
	env->content = ft_strdup(env_arr[0]);
	env->next = NULL;
	g_shell->env = env;
	i = 1;
	while (env_arr && env_arr[0] && env_arr[i])
	{
		new = malloc(sizeof (t_list));
		if (!new)
			return (1);
		new->content = ft_strdup(env_arr[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}

int	secret_to_shell(char **env_arr)
{
	t_list	*env;
	t_list	*new;
	int		i;

	env = malloc(sizeof (t_list));
	if (!env)
		return (1);
	env->content = ft_strdup(env_arr[0]);
	env->next = NULL;
	g_shell->secret = env;
	i = 1;
	while (env_arr && env_arr[0] && env_arr[i])
	{
		new = malloc(sizeof (t_list));
		if (!new)
			return (1);
		new->content = ft_strdup(env_arr[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}

void	*ft_env(void *b_struct)
{
	t_env	*env;
	t_list	*aux;

	env = (t_env*)b_struct;
	aux = env->env;
	if (!aux)
		return ((int*)1);
	while (aux)
	{
		if (aux->content)
			ft_putendl_fd(aux->content, 1);
		aux = aux->next;
	}
	if (g_shell->numOfPipes != 0)
		exit(0);
	return ((int*)0);
}
