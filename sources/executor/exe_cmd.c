/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:32:24 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/20 20:56:19 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_error(char *cmd, int n, t_shell *shell)
{
	if (n == 0)
	{	
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(cmd);
		if (shell->numOfPipes != 0)
			exit(1);
		return (errno);
	}
	else if (n == 1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		if (shell->numOfPipes != 0)
			exit(127);
		return (127);
	}
	return (0);
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

	env_arr = env_2_arr(shell->env);
	if ((cmd[0][0] == '.' && cmd[0][1] == '/') || access(cmd[0], X_OK) == 0)
		if (execve(cmd[0], cmd, env_arr) == -1)
			return (print_error(cmd[0], 0, shell));
	path = get_right_path(cmd[0], shell);
	if (path == NULL)
		return (print_error(cmd[0], 1, shell));
	if (execve(path, cmd, env_arr) == -1)
	{	
		free_arr(env_arr);
		ft_memdel(path);
		return (print_error(cmd[0], 0, shell));
	}
	return (0);
}
