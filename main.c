/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/11 18:05:05 by mbarylak         ###   ########.fr       */
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
	return (shell);
}

// 			printf("%s\n", inpt);
// 	}
// //	system("leaks minishell");
// 	return (shell->ret);
// }

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
	char	*input;
	char	**line;
	int		flag;
	// char	*quote;
	// t_shell	*shell;
	t_token *tokens;

	(void) argc;
	(void) argv;
	g_shell = init_shell();
	get_path(env);
	// env_to_shell(env, shell);
	while (g_shell->exit == 1)
	{
		input = readline(CYAN "minishell> " RESET);		// add_history(inpt);
		flag = 0;
		if (ft_strchr(input, '$'))
			flag = 1;
		g_shell->index = 0;
		g_shell->numOfArgs = 0;
		if (quote_analyzer(input) % 2 != 0)
		{
			printf("Error de comillas\n");
			// printf("\n> ");
			// while (shell->diff_quote % 2 != 0)
			// {
			// 	quote = readline("> ");
			// 	while (quote[i])
			// 	{
			// 		if (quote[i] == S_QUOTE)
			// 			shell->diff_quote += 1;
			// 		i++;
			// 	}
			// }
			exit(-1);
		}
		// else
		// 	line = split_input(input);

		// int i = 0;
		// while(line[i])
		// {
		// 	printf("line[%d]: %s\n", i, line[i]);
		// 	i++;
		// }

		line = split_input(input);

		if (ft_strncmp(line[0], "exit", 4) == 0)
			ft_exit(line);
		// else if (ft_strncmp(line[0], "pwd", 3) == 0)
		// 	ft_pwd();
		// else if (ft_strncmp(line[0], "env", 3) == 0)
		// 	ft_env(shell->env);
		// else if (ft_strncmp(line[0], "echo", 4) == 0)
		// 	ft_echo(line);
		// else if (ft_strncmp(line[0], "cd", 2) == 0)
		// 	ft_cd(line, shell->env);

		tokens = lexer(line);
		g_shell->tokens = tokens;
		

		int index = 0;
		// while (index < g_shell->numOfArgs)
		// {
		// 	printf("Index: %d\tType: %d\tData: %s\n", index, shell->tokens[index].type, shell->tokens[index].data);
		// 	index++;
		// }

		if (flag == 1)
			tokens = expander(tokens);

		index = 0;
		while (index < g_shell->numOfArgs)
		{
			printf("Index: %d\tType: %d\tData: %s\n", index, g_shell->tokens[index].type, g_shell->tokens[index].data);
			index++;
		}

		// free_shell(shell);
		// free(tokens);
		// free(line);
		
		// system("leaks minishell");

		// free(input);
		// free(g_shell);
		// exit(0);
	}
}
