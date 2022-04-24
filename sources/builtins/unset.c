/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:07:23 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/22 17:14:17 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_error(char *arg)
{
	char	*err_msg;
	char	*aux;

	aux = ft_strjoin("`", arg);
	err_msg = ft_strjoin(aux, "'");
	ft_memdel(aux);
	ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	ft_memdel(err_msg);
	return (1);
}

static int	len(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '=')
		i++;
	return (i);
}

static void	free_env_node(char *arg, t_list *env)
{
	t_list	*aux;

	if (ft_strncmp(arg, env->content, len(env->content)) == 0)
	{
		g_shell->env = g_shell->env->next;
		ft_memdel(env->content);
		ft_memdel(env);
		env = g_shell->env;
		return ;
	}
	while (env && env->next)
	{
		if (ft_strncmp(arg, env->next->content, len(env->next->content)) == 0)
		{
			aux = env->next->next;
			ft_memdel(env->next->content);
			ft_memdel(env->next);
			env->next = aux;
		}
		env = env->next;
	}
}

static void	free_secret_node(char *arg, t_list *env)
{
	t_list	*aux;

	if (ft_strncmp(arg, env->content, len(env->content)) == 0)
	{
		g_shell->secret = g_shell->secret->next;
		ft_memdel(env->content);
		ft_memdel(env);
		env = g_shell->secret;
		return ;
	}
	while (env && env->next)
	{
		if (ft_strncmp(arg, env->next->content, len(env->next->content)) == 0)
		{
			aux = env->next->next;
			ft_memdel(env->next->content);
			ft_memdel(env->next);
			env->next = aux;
		}
		env = env->next;
	}
}

int	ft_unset(char **arg)
{
	t_list	*env;
	t_list	*secret;
	int		i;
	int		flag;

	env = g_shell->env;
	secret = g_shell->secret;
	if (!arg[1])
		return (0);
	i = 1;
	while (arg[i])
	{
		flag = 0;
		if (is_valid(arg[i]) == -1)
			flag = print_error(arg[i]);
		if (flag == 0)
		{
			free_env_node(arg[i], env);
			free_secret_node(arg[i], secret);
		}
		i++;
	}
	return (0);
}
