/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:13:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/01 18:54:01 by mbarylak         ###   ########.fr       */
/*   Updated: 2022/06/08 12:12:01 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

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
static int	cd_aux(char *s, t_list *env)
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
	if (shell->pipes != 0)
		exit(0);
	if (ret < 0)
		return ((void*)(intptr_t)(ret * -1));	// Para acceder al int del return seria "*(int *)"
	return ((void*)(intptr_t)ret);				// o "(int)(intptr_t)"
}