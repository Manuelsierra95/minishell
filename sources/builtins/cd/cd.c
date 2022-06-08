/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:13:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/23 09:18:39 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

static void	print_error(int n, char *err)
{
	if (n == 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(err, STDERR_FILENO);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	else if (n == 1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(err, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	}
}

static int	update_env(char *s, t_list *env)
{
	char	buf[PATH_MAX];
	char	*path;

	path = NULL;
	if (!getcwd(buf, PATH_MAX) || !env)
		return (1);
	while (env && env->next)
	{
		if (ft_strncmp(env->content, s, ft_strlen(s)) == 0)
		{
			if (env->content)
				ft_memdel(env->content);
			path = ft_strjoin(s, buf);
			if (!path)
				return (1);
			env->content = ft_strdup(path);
			break ;
		}
		env = env->next;
	}
	ft_memdel(path);
	return (0);
}
static int	cd_aux(char *s, t_list *env)
{
	int		ret;
	char	*path;

	path = ft_getenv(s, env);
	if (!path)
	{
		ret = 1;
		print_error(0, s);
		return (ret);
	}
	update_env("OLDPWD=", env);
	ret = chdir(path);
	if (ret == -1)
		print_error(1, path);
	update_env("PWD=", env);
	ft_memdel(path);
	return (ret);
}


void	*ft_cd(void *b_struct)
{
	int		ret;
	t_cd	*cd;

	cd = (t_cd*)b_struct;
	ret = 0;
	if (!cd->arg[1])
		ret = cd_aux("HOME", cd->env);
	else if (cd->arg[1] && ft_strncmp(cd->arg[1], "-", 1) == 0)
	{	
		ret = cd_aux("OLDPWD", cd->env);
		if (ret == 0)
			ft_pwd((int*)1);
	}
	else
	{
		update_env("OLDPWD=", cd->env);
		ret = chdir(cd->arg[1]);
		if (ret == -1)
			print_error(1, cd->arg[1]);
		update_env("PWD=", cd->env);
	}
	if (ret < 0)
		return ((void*)(intptr_t)(ret * -1));	// Para acceder al int del return seria "*(int *)"
	return ((void*)(intptr_t)ret);				// o "(int)(intptr_t)"
}
