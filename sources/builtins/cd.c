/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:13:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/01 18:54:01 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(int n, char *err, t_shell *shell)
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
	if (shell->pipes != 0)
		exit(1);
}

static int	update_env(char *s, t_shell *shell)
{
	char	buf[PATH_MAX];
	char	*path;
	t_list	*aux_env;

	path = NULL;
	aux_env = shell->env;
	if (!getcwd(buf, PATH_MAX) || !shell->env)
		return (1);
	while (aux_env && aux_env->next)
	{
		if (ft_strncmp(aux_env->content, s, ft_strlen(s)) == 0)
		{
			if (aux_env->content)
				ft_memdel(aux_env->content);
			path = ft_strjoin(s, buf);
			if (!path)
				return (1);
			aux_env->content = ft_strdup(path);
			break ;
		}
		aux_env = aux_env->next;
	}
	ft_memdel(path);
	return (0);
}

static int	cd_aux(char *s, t_shell *shell)
{
	int		ret;
	char	*path;

	path = ft_getenv(s, shell->env);
	if (!path)
	{
		ret = 1;
		print_error(0, s, shell);
		return (ret);
	}
	update_env("OLDPWD=", shell);
	ret = chdir(path);
	if (ret == -1)
		print_error(1, path, shell);
	update_env("PWD=", shell);
	ft_memdel(path);
	return (ret);
}

int	ft_cd(char **arg, t_shell *shell)
{
	int		ret;

	ret = 0;
	if (!arg[1])
		ret = cd_aux("HOME", shell);
	else if (arg[1] && ft_strncmp(arg[1], "-", 1) == 0)
	{	
		ret = cd_aux("OLDPWD", shell);
		if (ret == 0)
			ft_pwd(1, shell);
	}
	else
	{
		update_env("OLDPWD=", shell);
		ret = chdir(arg[1]);
		if (ret == -1)
			print_error(1, arg[1], shell);
		update_env("PWD=", shell);
	}
	if (shell->pipes != 0)
		exit(0);
	if (ret < 0)
		return (ret * -1);
	return (ret);
}
