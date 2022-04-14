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

// 			printf("%s\n", inpt);
// 	}
// //	system("leaks minishell");
// 	return (shell->ret);
// }

int	args_in_line(char **line)
{
	int	size;

	size = 0;
	while(line[size])
	{
		printf("line: %s\n", line[size]);
		size++;
	}
	return (size);
}


int	main(int argc, char **argv, char **env)
{
	char	*input;
	char	**line;
	// char	*quote;
	t_shell	*shell;
	t_token *tokens;

	(void) argc;
	(void) argv;
	shell = init_shell();
	get_path(shell, env);
	env_to_shell(env, shell);

	while (shell->exit == 1)
	{
		input = readline("minishell> ");		// add_history(inpt);
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
			
		}
		else
			line = u_split(input, ' ', quote_analyzer(input));


		// if (ft_strncmp(line[0], "pwd", 3) == 0)
		// 	ft_pwd();
		if (ft_strncmp(line[0], "exit", 4) == 0)
			ft_exit(line, shell);
		// else if (ft_strncmp(line[0], "env", 3) == 0)
		// 	ft_env(shell->env);
		// else if (ft_strncmp(line[0], "echo", 4) == 0)
		// 	ft_echo(line);
		// else if (ft_strncmp(line[0], "cd", 2) == 0)
		// 	ft_cd(line, shell->env);
		tokens = lexer(shell, args_in_line(line), line);
		shell->tokens = tokens;
		int index = 0;
		while (index < shell->numOfArgs)
		{
			printf("Index: %d\tType: %d\tData: %s\n", index, shell->tokens[index].type, shell->tokens[index].data);
			index++;
		}
	}
}
