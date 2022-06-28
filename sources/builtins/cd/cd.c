/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:13:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/21 14:46:27 by mbarylak         ###   ########.fr       */
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
		perror(err);
	}
	if (shell->numOfPipes != 0)
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
	char	*path;

	path = ft_getenv(s, shell->env);
	if (!path)
	{
		print_error(0, s, shell);
		return (1);
	}
	update_env("OLDPWD=", shell);
	if (chdir(path) == -1)
		print_error(1, path, shell);
	update_env("PWD=", shell);
	ft_memdel(path);
	return (0);
}

void	*ft_cd(void *b_struct)
{
	int		ret;
	t_cd	*cd;

	cd = (t_cd *)b_struct;
	ret = 0;
	if (!cd->arg[1])
		ret = cd_aux("HOME", g_shell);
	else if (cd->arg[1] && ft_strncmp(cd->arg[1], "-", 1) == 0)
	{	
		ret = cd_aux("OLDPWD", g_shell);
		if (ret == 0)
			ft_pwd(&cd->fd);
	}
	else
	{
		update_env("OLDPWD=", g_shell);
		ret = chdir(cd->arg[1]);
		if (ret == -1)
			print_error(1, cd->arg[1], g_shell);
		update_env("PWD=", g_shell);
	}
	if (g_shell->numOfPipes != 0)
		exit(0);
	if (ret < 0)
		return ((void *)(intptr_t)(ret * -1));
	return ((void *)(intptr_t)ret);
}
