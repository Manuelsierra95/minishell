/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/01 19:39:27 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(char **env)
{
	g_shell.exit = 1;
	g_shell.ret = 0;
	g_shell.pipes = 0;
	env_to_shell(env);
	secret_to_shell(env);
}

void	init_exec(t_exec *exe)
{
	exe->fd_in = 0;
	exe->fd_out = 1;
	exe->cmds = NULL;
}

void	ft_free(char *inpt, char **line, t_cmd *cmds)
{
	free_arr(line);
	ft_memdel(inpt);
	free_cmds(cmds);
}

int	main(int argc, char **argv, char **env)
{
	char	*inpt;
	char	**line;
	t_exec	exe;
	int		i;

	(void) argc;
	(void) argv;
	init_shell(env);
	while (g_shell.exit == 1)
	{
		init_exec(&exe);
		inpt = readline("minishell> ");
		add_history(inpt);
		if (inpt[0] != 0 && inpt[0] != 32)
		{	
			line = ft_split(inpt, '|');
			pipe_counter(inpt, &g_shell);
			i = -1;
			while (line[++i])
				add_cmds(line[i], &exe.cmds);
			exec(&exe, &g_shell);
		}
		ft_free(inpt, line, exe.cmds);
	}
	return (g_shell.ret);
}
