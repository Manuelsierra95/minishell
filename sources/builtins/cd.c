/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:13:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/20 19:21:12 by mbarylak         ###   ########.fr       */
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

static int	cd_aux(char *path, char *s, t_list *env)
{
	int	ret;
	int	err;

	err = 0;
	if (s != NULL && !path)
	{
		path = ft_getenv(s, env);
		if (!path && !err)
		{
			ret = 1;
			print_error(0, s);
			err = 1;
		}
	}
	update_env("OLDPWD", env);
	ret = chdir(path);
	if (ret == -1 && !err)
		print_error(1, path);
	update_env("PWD", env);
	return (ret);
}

int	ft_cd(char **arg, t_list *env)
{
	int		ret;

	ret = 0;
	if (!arg[1])
		ret = cd_aux(NULL, "HOME", env);
	else if (arg[1] && ft_strncmp(arg[1], "-", 1) == 0)
	{	
		ret = cd_aux(NULL, "OLDPWD", env);
		if (ret == 0)
			ft_pwd(1);
	}
	else
		ret = cd_aux(arg[1], NULL, env);
	if (ret < 0)
		return (ret * -1);
	return (ret);
}
