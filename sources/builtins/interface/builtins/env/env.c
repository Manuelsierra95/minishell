/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:52:19 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/22 16:43:00 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_env(t_list *env, int fd)
{
	if (!env)
		return (1);
	while (env && env->next != NULL)
	{
		if (env->content)
			ft_putendl_fd(env->content, fd);
		env = env->next;
	}
	if (env->content)
		ft_putendl_fd(env->content, fd);
	return (0);
}