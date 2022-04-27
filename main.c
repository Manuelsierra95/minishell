/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/22 17:14:15 by mbarylak         ###   ########.fr       */
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
	return (shell);
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

int	main(int argc, char **argv, char **env)
{
	char	*inpt;
	char	**line;
	int		flag;

	(void) argc;
	(void) argv;
	g_shell = init_shell();
	env_to_shell(env);
	secret_to_shell(env);
	get_path();
	while (g_shell->exit == 1)
	{
		inpt = readline(CYAN "minishell> " RESET);
		add_history(inpt);
		flag = 0;
		if (ft_strchr(inpt, '$'))
			flag = 1;
		g_shell->index = 0;
		g_shell->numOfArgs = 0;
		if (quote_analyzer(inpt) % 2 != 0)
		{
			printf("Error de comillas\n");
			exit(-1);
		}
		line = split_input(inpt);
		shell_cmds(inpt, line);
		g_shell->tokens = lexer(line);
		free(line);
		if (flag == 1)
			g_shell->tokens = expander(g_shell->tokens);

		// int index = 0;
		// while (index < g_shell->numOfArgs)
		// {
		// 	printf("Index: %d\tType: %d\tData: %s\n", index, g_shell->tokens[index].type, g_shell->tokens[index].data);
		// 	index++;
		// }

		free(g_shell->tokens);
	}
//	system("leaks minishell");
	return (g_shell->ret);
}
