/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:13:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/13 22:04:02 by mbarylak         ###   ########.fr       */
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

static int	update_env(char *s, t_env *env)
{
	char	buf[PATH_MAX];
	char	*path;

	if (!getcwd(buf, PATH_MAX) || !env)
		return (1);
	while (env && env->next)
	{
		if (ft_strncmp(env->content, s, ft_strlen(s)) == 0)
		{
			if (env->content)
				free(env->content);
			path = ft_strjoin(s, "=");
			path = ft_strjoin(path, buf);
			if (!path)
				return (1);
			env->content = path;
			break ;
		}
		env = env->next;
	}
	return (0);
}

static int	cd_aux(char *path, t_env *env)
{
	int	ret;

	update_env("OLDPWD", env);
	ret = chdir(path);
	if (ret == -1)
		print_error(1, path);
	update_env("PWD", env);
	return (ret);
}

int	ft_cd(char **arg, t_env *env)
{
	int		ret;
	char	*path;

	ret = 1;
	if (!arg[1])
	{
		path = getenv("HOME");
		if (!path)
			print_error(0, "HOME");
		ret = cd_aux(path, env);
	}
	else if (arg[1] && ft_strncmp(arg[1], "-", 1) == 0)
	{
		path = getenv("OLDPWD");
		if (!path)
			print_error(0, "OLDPWD");
		ret = cd_aux(path, env);
		ft_pwd();
	}
	else
		ret = cd_aux(arg[1], env);
	return (ret);
}
