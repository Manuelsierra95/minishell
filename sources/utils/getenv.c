/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:57:05 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/12 19:39:02 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *arg, t_list *env)
{
	char	*s;
	t_list	*aux;
	char	*value;

	aux = env;
	s = NULL;
	while (aux->next)
	{
		if (ft_strncmp(aux->content, arg, ft_strlen(arg)) == 0)
		{
			s = ft_strdup(aux->content);
			break ;
		}
		aux = aux->next;
	}
	if (s)
	{	
		value = get_value(s);
		ft_memdel(s);
		return (value);
	}
	return (NULL);
}

t_list	*until_name(char *name, t_list *env)
{
	t_list	*aux;
	char	*env_name;

	aux = env;
	while (aux && aux->next)
	{
		env_name = get_name(aux->content);
		if (ft_strcmp(name, env_name) == 0)
		{
			ft_memdel(env_name);
			return (aux);
		}
		ft_memdel(env_name);
		aux = aux->next;
	}
	return (NULL);
}

char	**env_2_arr(t_list *env)
{
	t_list	*aux;
	int		i;
	char	**env_arr;

	aux = env;
	env_arr = malloc(sizeof(char *) * (ft_lstsize(aux) + 1));
	if (!env_arr)
		return (NULL);
	i = 0;
	while (aux)
	{
		if (aux->content)
			env_arr[i] = ft_strdup(aux->content);
		i++;
		aux = aux->next;
	}
	env_arr[i] = NULL;
	return (env_arr);
}
