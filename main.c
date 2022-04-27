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

t_shell	*init_shell(char **env)
{
	t_shell	*shell;

	shell = malloc(sizeof (t_shell));
	shell->exit = 1;
	shell->ret = 0;
	shell->envv = env;
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
			line = ft_split(inpt, ' ');
		if (line[0] && ft_strcmp(line[0], "pwd") == 0)
			ft_pwd(1);
		else if (line[0] && ft_strcmp(line[0], "exit") == 0)
			ft_exit(line);
		else if (line[0] && ft_strcmp(line[0], "env") == 0)
			ft_env(g_shell->env, 1);
		else if (line[0] && ft_strcmp(line[0], "echo") == 0)
			ft_echo(1, line);
		else if (line[0] && ft_strcmp(line[0], "cd") == 0)
			ft_cd(line, g_shell->env);
		else if (line[0] && ft_strcmp(line[0], "export") == 0)
			ft_export(line, g_shell->env, g_shell->secret, 1);
		else if (line[0] && ft_strcmp(line[0], "secret") == 0)
			ft_env(g_shell->secret, 1);
		else if (line[0] && ft_strcmp(line[0], "unset") == 0)
			ft_unset(line);
		else
			printf("%s", inpt);
	}
//	system("leaks minishell");
	return (g_shell->ret);

int	main(int argc, char **argv, char **env)
{
	char	*input;
	char	**line;
	int		flag;
	// char	*quote;
	// t_shell	*shell;

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
			exit(-1);
		}
		// else
		// 	line = split_input(input);

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

		g_shell->tokens = lexer(line);
		free(line);
		if (flag == 1)
			g_shell->tokens = expander(g_shell->tokens);

		int index = 0;
		while (index < g_shell->numOfArgs)
		{
			printf("Index: %d\tType: %d\tData: %s\n", index, g_shell->tokens[index].type, g_shell->tokens[index].data);
			index++;
		}

		free(g_shell->tokens);
		
		// system("leaks minishell");
	}
}
