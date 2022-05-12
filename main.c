/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
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

void	free_matrix(char **line)
{
	int	y;

	y = -1;
	while (line[++y])
	{
		free(line[y]);
	}
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

int	main(int argc, char **argv, char **env)//TODO: Usar buildins para el tokenizado || Pasar numero de pipes
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
		g_shell->numOfPipes = 0;
		if (quote_analyzer(inpt) % 2 != 0)
		{
			printf("Error de comillas\n");
			exit(-1);
		}
		write(1, "Aqui llega\n", 11);
		line = split_input(inpt);
		// shell_cmds(inpt, line);
		g_shell->tokens = lexer(line);
		if (!check_for_errors(g_shell->tokens)) // NO detecta exit y demas como comandos y salta error!!
		{
			if (flag == 1)
				g_shell->tokens = expander(g_shell->tokens);
			
			g_shell->tree = create_tree();
			shell_loop();


			// {
			// 	printf("Index: %d\tType: %d\tData: %s\n", index, g_shell->tokens[index].type, g_shell->tokens[index].data);
			// 	index++;
			// }

		}

		// free_matrix(line);
		// free(g_shell->tokens);
			// while (index < g_shell->numOfArgs)
			// int index = 0;
	}
	return (g_shell->ret);
}
