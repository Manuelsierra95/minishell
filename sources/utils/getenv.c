/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:57:05 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/11 16:37:13 by mbarylak         ###   ########.fr       */
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

static int	env_len(t_list *env)
{
	int	len;

	len = 0;
	while (env && env->next)
	{
		if (env->content)
		{
			len += ft_strlen(env->content);
			len++;
		}
		env = env->next;
	}
	return (len);
}

char	*env_2_str(t_list *env)
{
	char	*env_str;
	int		i;
	int		j;

	env_str = (char *) malloc(env_len(env) + 1);
	if (!env_str)
		return (NULL);
	i = 0;
	while (env && env->next)
	{
		if (env->content != NULL)
		{
			j = 0;
			while (env->content[j])
				env_str[i++] = env->content[j++];
		}
		if (env->next->next != NULL)
			env_str[i++] = '\n';
		env = env->next;
	}
	env_str[i] = '\0';
	return (env_str);
}

char	**env_2_arr(t_list *env)
{
	char	**env_arr;
	char	*env_str;

	env_str = env_2_str(env);
	env_arr = ft_split(env_str, '\n');
	ft_memdel(env_str);
	return (env_arr);
}
