/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:13:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/11 13:19:58 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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


int	ft_cd(char **arg, t_list *env)
{
	int		ret;

	ret = 0;
	if (!arg[1])
		ret = cd_aux("HOME", env);
	else if (arg[1] && ft_strncmp(arg[1], "-", 1) == 0)
	{	
		ret = cd_aux("OLDPWD", env);
		if (ret == 0)
			ft_pwd(1);
	}
	else
	{
		update_env("OLDPWD=", env);
		ret = chdir(arg[1]);
		if (ret == -1)
			print_error(1, arg[1]);
		update_env("PWD=", env);
	}
	if (ret < 0)
		return (ret * -1);
	return (ret);
}