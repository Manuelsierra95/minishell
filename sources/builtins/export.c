/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:56:26 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/27 17:06:22 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *arg, t_shell *shell)
{
	char	*err_msg;
	char	*aux;

	aux = ft_strjoin("`", arg);
	err_msg = ft_strjoin(aux, "'");
	ft_memdel(aux);
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	ft_memdel(err_msg);
	if (shell->pipes != 0)
		exit(1);
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

int	ft_export(char **arg, t_shell **shell, int fd)
{
	int	i;
	int	has_eq;
	int	n;

	i = 1;
	if (!arg[i])
		return (print_secret(*shell, fd));
	while (arg[i])
	{
		has_eq = is_valid(arg[i]);
		if (has_eq == -1)
			print_error(arg[i], *shell);
		n = is_in_env(arg[i], has_eq, (*shell)->env);
		n += is_in_env(arg[i], has_eq, (*shell)->secret);
		if (n <= 1)
			if (has_eq == 1)
				add_2_env(arg[i], (*shell)->env);
		if (n == 0)
			add_2_env(arg[i], (*shell)->secret);
		i++;
	}
	if ((*shell)->pipes != 0)
		exit(0);
	return (0);
}
