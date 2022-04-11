/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:52:19 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/11 18:07:03 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_to_lst(char **arg)
{
	t_env	*env;
	t_env	*first;
	t_env	*new;
	int		i;

	i = 0;
	env = malloc(sizeof (t_env));
	if (!env)
		return (NULL);
	env->content = ft_strdup(arg[0]);
	env->next = NULL;
	first = env;
	i = 1;
	while (arg && arg[0] && arg[i])
	{
		new = malloc(sizeof (t_env));
		if (!new)
			return (NULL);
		new->content = ft_strdup(arg[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	env = first;
	return (env);
}

int	ft_env(t_env *env)
{
	if (!env)
		return (1);
	while (env && env->next != NULL)
	{
		ft_putendl_fd(env->content, STDOUT_FILENO);
		env = env->next;
	}
	if (env)
		ft_putendl_fd(env->content, STDOUT_FILENO);
	return (0);
}
