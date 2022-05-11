/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:32:24 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/11 17:35:46 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *cmd, int n)
{
	if (n == 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	}
	else if (n == 1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
	}
}

char	**get_env_path(t_list *env)
{
	char	**env_path;

	while (env->next)
	{
		if (ft_strncmp(env->content, "PATH", 4) == 0)
		{	
			env_path = ft_split(ft_strchr(env->content, '/'), ':');
			return (env_path);
		}
		env = env->next;
	}
	return (NULL);
}

char	*get_right_path(char *cmd, t_shell *shell)
{
	char	*path;
	char	**env_path;
	int		i;

	env_path = get_env_path(shell->env);
	if (!env_path)
		return (NULL);
	i = 0;
	while (env_path[i])
	{
		cmd = ft_strjoin("/", cmd);
		path = ft_strjoin(env_path[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

int	exe_cmd(char **cmd, t_shell *shell)
{
	char	*path;
	char	**env_arr;
	int		err_num;

	path = get_right_path(cmd[0], shell);
	if (path == NULL)
	{
		print_error(cmd[0], 1);
		return (127);
	}
	env_arr = env_2_arr(shell->env);
	err_num = execve(path, cmd, env_arr);
	free_arr(env_arr);
	if (err_num == -1)
	{	
		print_error(cmd[0], 0);
		return (127);
	}
	ft_memdel(path);
	return (err_num);
}
