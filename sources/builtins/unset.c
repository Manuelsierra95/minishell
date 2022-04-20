/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:07:23 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/20 20:22:43 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_error(char *arg)
{
	char	*err_msg;

	err_msg = ft_strjoin("`", arg);
	err_msg = ft_strjoin(err_msg, "'");
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

static void	free_node(char *arg, t_list **env)
{
	t_list	*aux;

	if (ft_strncmp(arg, (*env)->content, len((*env)->content)) == 0)
	{
		aux = (*env)->next;
		ft_memdel((*env)->content);
		ft_memdel(*env);
		*env = aux;
		return ;
	}
	while (env && *env && (*env)->next)
	{
		if (ft_strncmp(arg, (*env)->next->content, len((*env)->next->content)) == 0)
		{
			aux = (*env)->next->next;
			ft_memdel((*env)->next->content);
			ft_memdel((*env)->next);
			(*env)->next = aux;
		}
		*env = (*env)->next;
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
			free_node(arg[i], &env);
			free_node(arg[i], &secret);
		}
		i++;
	}
	return (0);
}
