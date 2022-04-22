/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:57:05 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/21 18:29:36 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *arg, t_list *env)
{
	char	*s;
	t_list	*aux;

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
	if (s == NULL)
		return (NULL);
	else
		return (get_value(s));
}

t_list	*until_name(char *name, t_list *env)
{
	t_list	*aux;
	char	*env_name;

	aux = env;
	env_name = ft_strdup("");
	while (aux && aux->next)
	{
		env_name = get_name(aux->content);
		if (ft_strcmp(name, env_name) == 0)
		{
			free(env_name);
			return (aux);
		}
		aux = aux->next;
	}
	free(env_name);
	return (NULL);
}
