/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:07:23 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/22 22:04:40 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

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

void	*ft_unset(void *b_struct)
{
	t_list	*env;
	t_list	*secret;
	int		i;
	int		flag;
	t_unset	*unset;

	unset = (t_unset*)b_struct;
	env = g_shell->env;
	secret = g_shell->secret;
	if (!unset->arg[1])
		return (0);
	i = 1;
	while (unset->arg[i])
	{
		flag = 0;
		if (is_valid(unset->arg[i]) == -1)
			flag = print_error(unset->arg[i]);
		if (flag == 0)
		{
			free_env_node(unset->arg[i], env);
			free_secret_node(unset->arg[i], secret);
		}
		i++;
	}
	return (0);
}
