/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/17 21:09:42 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*init_shell(char **env)
{
	t_shell	*shell;

	shell = malloc(sizeof (t_shell));
	shell->exe = malloc(sizeof (t_exec));
	shell->exe->fd_in = 0;
	shell->exe->fd_out = 1;
	shell->exe->oldfd_in = 0;
	shell->exe->oldfd_out = 1;
	shell->exe->cmds = malloc(sizeof (t_cmd));
	shell->exe->cmds->arg = NULL;
	shell->exe->cmds->next = NULL;
	shell->exe->cmds->prev = NULL;
	shell->exit = 1;
	shell->ret = 0;
	shell->env = NULL;
	shell->secret = NULL;
	shell->pipes = 0;
	return (shell);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*inpt;
	char	**line;
	char	**cmd;
	int		i;

	(void) argc;
	(void) argv;
	g_shell = init_shell(env);
	env_to_shell(env);
	secret_to_shell(env);
	while (g_shell->exit == 1)
	{
		inpt = readline("minishell> ");
		add_history(inpt);
		if (inpt != NULL || ft_strcmp(inpt, "\n") == 0)
		{	
			line = ft_split(inpt, '|');
			pipe_counter(inpt, g_shell);
			ft_memdel(inpt);
		}
		i = 0;
		while (line[i])
		{
			cmd = ft_split(line[i], ' ');
			if (cmd[0] && is_builtin(cmd[0]))
				exec_builtin(cmd, g_shell, 1);
			else
				exe_child(cmd, g_shell);
			free_arr(cmd);
			i++;
		}
		free_arr(line);
	}
	return (g_shell->ret);
}
