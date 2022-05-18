/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/18 21:02:19 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*init_shell(void)
{
	t_shell	*shell;

	shell = malloc(sizeof (t_shell));
	shell->exit = 1;
	shell->ret = 0;
	shell->env = NULL;
	shell->secret = NULL;
	shell->pipes = 0;
	return (shell);
}

t_exec	*init_exec(void)
{
	t_exec	*exe;

	exe = malloc(sizeof (t_exec));
	exe->fd_in = 0;
	exe->fd_out = 1;
	exe->oldfd_in = 0;
	exe->oldfd_out = 1;
	exe->cmds = malloc(sizeof (t_cmd));
	exe->cmds->arg = NULL;
	exe->cmds->prev = NULL;
	exe->cmds->next = NULL;
	return (exe);
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
	//char	**cmd;
	t_exec	*exe;
	int		i;

	(void) argc;
	(void) argv;
	g_shell = init_shell();
	exe = init_exec();
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
			exe->cmds = add_cmds(line[i], exe->cmds, i);
			/*cmd = ft_split(line[i], ' ');
			if (cmd[0] && is_builtin(cmd[0]))
				exec_builtin(cmd, g_shell, 1);
			else
				exe_child(cmd, g_shell);*/
			//free_arr(cmd);
			i++;
		}
		while (exe->cmds)
		{
			if (exe->cmds->prev == NULL)
			{	
				printf("el primer comando es: ");
				print_env(exe->cmds->arg);
			}
			else if (exe->cmds->prev && exe->cmds->next)
			{
				printf("el comando de en medio es: ");
				print_env(exe->cmds->arg);
			}
			else if (exe->cmds->next == NULL)
			{
				printf("el último comando es: ");
				print_env(exe->cmds->arg);
			}
			exe->cmds = exe->cmds->next;
		}
		free_arr(line);
	}
	return (g_shell->ret);
}
