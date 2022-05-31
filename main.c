/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/05/31 19:55:21 by mbarylak         ###   ########.fr       */
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
	exe->cmds = NULL;
	return (exe);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		dprintf(2, "%s", env[i]);
		i++;
	}
}

void	print_list(t_list *env)
{
	t_list	*aux;

	aux = env;
	while (aux)
	{
		if (aux->content)
			dprintf(2, "%s\n", aux->content);
		aux = aux->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*inpt;
	char	**line;
	t_exec	*exe;
	int		i;

	(void) argc;
	(void) argv;
	g_shell = init_shell();
	env_to_shell(env);
	secret_to_shell(env);
	while (g_shell->exit == 1)
	{
		exe = init_exec();
		inpt = readline("minishell> ");
		add_history(inpt);
		if (inpt[0] != 0 && inpt[0] != 32)
		{	
			line = ft_split(inpt, '|');
			pipe_counter(inpt, g_shell);
			ft_memdel(inpt);
			i = 0;
			while (line[i])
			{
				add_cmds(line[i], &exe->cmds);
				i++;
			}
			exec(exe, g_shell);
			free_arr(line);
		}
		free_cmds(exe->cmds);
	}
	return (g_shell->ret);
}
