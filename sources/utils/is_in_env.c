/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:56:37 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/18 20:43:22 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_in_env(char *arg, int ret, t_list *env)
{
	char	*name;
	t_list	*first;

	if (ret == -1)
		return (1);
	name = get_name(arg);
	first = env;
	if (ret == 1 && name_in_env(name, env))
	{
		env = until_name(name, env);
		ft_memdel(env->content);
		env->content = ft_strdup(arg);
		env = first;
		free(name);
		return (1);
	}
	else if (ret == 0 && name_in_env(name, env))
	{
		free(name);
		return (1);
	}
	free(name);
	return (0);
}

char	*get_name(char *arg)
{
	char	*name;
	int		i;

	i = 0;
	name = malloc(ft_strlen(arg));
	if (!name)
		return (NULL);
	while (arg[i] && arg[i] != '=')
	{
		name[i] = arg[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char	*get_value(char *arg)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i + 1])
		return (ft_strdup(&arg[i + 1]));
	else
		return (ft_strdup(""));
}

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	name_in_env(char *name, t_list *env)
{
	char	*env_name;
	t_list	*aux;

	env_name = ft_strdup("");
	aux = env;
	while (aux && aux->next)
	{
		env_name = get_name(aux->content);
		if (ft_strcmp(name, env_name) == 0)
		{
			free(env_name);
			return (1);
		}
		aux = aux->next;
	}
	free(env_name);
	return (0);
}
