/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:56:26 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/18 20:29:40 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_error(char *arg)
{
	char	*err_msg;

	err_msg = ft_strjoin("`", arg);
	err_msg = ft_strjoin(err_msg, "'");
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	free(err_msg);
	return (1);
}

int	is_valid(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
		return (-1);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (-1);
		i++;
	}
	if (arg[i] && arg[i] == '=')
		return (1);
	return (0);
}

int	add_2_env(char *arg, t_list *env)
{
	t_list	*new;
	t_list	*aux;

	if (env && env->content == NULL)
	{
		env->content = ft_strdup(arg);
		return (0);
	}
	new = malloc(sizeof (t_list));
	if (!new)
		return (-1);
	new->content = ft_strdup(arg);
	while (env && env->next && env->next->next)
		env = env->next;
	aux = env->next;
	env->next = new;
	new->next = aux;
	return (0);
}

int	ft_export(char **arg, t_list *env, t_list *secret, int fd)
{
	int	i;
	int	ret;
	int	n;

	i = 1;
	if (!arg[i])
		return (print_secret(secret, fd));
	while (arg[i])
	{
		ret = is_valid(arg[i]);
		if (ret == -1)
			return (print_error(arg[i]));
		n = is_in_env(arg[i], ret, env);
		n += is_in_env(arg[i], ret, secret);
		if (n <= 1)
			if (ret == 1)
				add_2_env(arg[i], env);
		if (n == 0)
			add_2_env(arg[i], secret);
		i++;
	}
	return (0);
}