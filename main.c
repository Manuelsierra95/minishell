/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/06 12:06:59 by msierra-         ###   ########.fr       */
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
	shell->exit_stat = 0;
	shell->secret = NULL;
	put_builtins(shell->map);
	return (shell);
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


void	free_shell(t_shell *shell)
{
	int	x;

	x = 0;
	while (shell->path[x])
		free(shell->path[x]);
	free(shell->tokens);
	free(shell);
}

int	main(int argc, char **argv, char **env)//TODO: Cambiar campos de los getters
{
	char	*inpt;
	char	**line;
	t_exec	exe;
	int		i;
	int		flag;

	(void) argc;
	(void) argv;
	init_shell(env);
	get_path();
	while (g_shell.exit == 1)
	{
		init_exec(&exe);
		inpt = readline("minishell> ");
		add_history(inpt);
		flag = 0;
		if (ft_strchr(inpt, '$'))
			flag = 1;
		g_shell->index = 0;
		g_shell->numOfArgs = 0;
		g_shell->numOfPipes = 0;
		line = split_input(inpt);
		// shell_cmds(inpt, line);
		g_shell->tokens = lexer(line);
		if (!check_for_errors(g_shell->tokens))
		{
			if (flag == 1)
				g_shell->tokens = expander(g_shell->tokens);
			
			g_shell->tree = create_tree();
			shell_loop();
			exec(&exe, &g_shell);
		}

		// free_matrix(line);
		// free(g_shell->tokens);
			// while (index < g_shell->numOfArgs)
			// int index = 0;
	}
	clean_map(g_shell->map);
	return (g_shell->ret);
}
