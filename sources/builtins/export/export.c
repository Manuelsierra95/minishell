/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:56:26 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/08 12:12:13 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

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
	if (shell->numOfPipes != 0)
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

void	*ft_export(void *b_struct)
{
	int			i;
	int			ret;
	int			n;
	t_export	*export;

	export = (t_export*)b_struct;
	i = 1;
	if (!export->arg[i])
		return ((void*)(intptr_t)print_secret(g_shell, export->fd));
	while (export->arg[i])
	{
		ret = is_valid(export->arg[i]);
		if (ret == -1)
			print_error(export->arg[i], g_shell);
		n = is_in_env(export->arg[i], ret, g_shell->env);
		n += is_in_env(export->arg[i], ret, g_shell->secret);
		if (n <= 1)
			if (ret == 1)
				add_2_env(export->arg[i], g_shell->env);
		if (n == 0)
			add_2_env(export->arg[i], g_shell->secret);
		i++;
	}
	if (g_shell->numOfPipes != 0)
		exit(0);
	return (0);
}
