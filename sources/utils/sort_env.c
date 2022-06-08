/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:20:09 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/27 16:58:38 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char	*ft_msg_aux(char *arg)
{
	char	*value;
	char	*aux;
	char	*msg;

	value = get_value(arg);
	aux = ft_strjoin("\"", value);
	ft_memdel(value);
	value = ft_strjoin(aux, "\"");
	ft_memdel(aux);
	msg = get_name(arg);
	aux = ft_strjoin(msg, "=");
	ft_memdel(msg);
	msg = ft_strjoin(aux, value);
	ft_memdel(aux);
	ft_memdel(value);
	return (msg);
}

static char	*ft_msg(char *arg)
{
	char	*msg;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (arg[i++] && flag == 0)
		if (arg[i] == '=')
			flag = 1;
	if (flag == 1)
		msg = ft_msg_aux(arg);
	else
		msg = ft_strdup(arg);
	return (msg);
}

int	print_secret(t_shell *shell, int fd)
{
	int		i;
	char	**env_arr;
	char	*msg;

	env_arr = env_2_arr(shell->secret);
	if (!env_arr)
		return (1);
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
	if (shell->pipes != 0)
		exit(0);
	return (0);
}
