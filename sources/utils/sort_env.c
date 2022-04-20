/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:09 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/20 20:24:57 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	sort_env(char **env_arr, int env_len)
{
	char	*aux;
	int		sorted;
	int		i;

	sorted = 0;
	while (env_arr && sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(env_arr[i], env_arr[i + 1]) > 0)
			{
				aux = env_arr[i];
				env_arr[i] = env_arr[i + 1];
				env_arr[i + 1] = aux;
				sorted = 0;
			}
			i++;
		}
		env_len--;
	}
}

static char	*ft_msg(char *arg)
{
	char	*value;
	char	*msg;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (arg[i++] && flag == 0)
		if (arg[i] == '=')
			flag = 1;
	if (flag == 1)
	{
		value = get_value(arg);
		value = ft_strjoin("\"", value);
		value = ft_strjoin(value, "\"");
		msg = get_name(arg);
		msg = ft_strjoin(msg, "=");
		msg = ft_strjoin(msg, value);
		ft_memdel(value);
	}
	else
		msg = ft_strdup(arg);
	return (msg);
}

int	print_secret(t_list *secret, int fd)
{
	int		i;
	char	*env_str;
	char	**env_arr;
	char	*msg;

	env_str = env_2_str(secret);
	if (!env_str)
		return (1);
	env_arr = ft_split(env_str, '\n');
	ft_memdel(env_str);
	sort_env(env_arr, arr_len(env_arr));
	i = 0;
	while (env_arr[i])
	{
		ft_putstr_fd("declare -x ", fd);
		msg = ft_msg(env_arr[i]);
		ft_putendl_fd(msg, fd);
		ft_memdel(msg);
		i++;
	}
	free_arr(env_arr);
	return (0);
}
