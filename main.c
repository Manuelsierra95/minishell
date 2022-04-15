/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/13 19:14:24 by mbarylak         ###   ########.fr       */
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
	shell->errnbr = 0;
	shell->secret = NULL;
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
	t_shell	*shell;

	(void) argc;
	(void) argv;
	shell = init_shell(env);
	env_to_shell(env, shell);
	secret_to_shell(env, shell);
	while (shell->exit == 1)
	{
		inpt = readline("minishell> ");
		add_history(inpt);
		if (inpt != NULL || ft_strncmp(inpt, "\n", 1) == 0)
			line = ft_split(inpt, ' ');
		if (line[0] && ft_strncmp(line[0], "pwd", 3) == 0)
			ft_pwd();
		else if (line[0] && ft_strncmp(line[0], "exit", 4) == 0)
			ft_exit(line, shell);
		else if (line[0] && ft_strncmp(line[0], "env", 3) == 0)
			ft_env(shell->env);
		else if (line[0] && ft_strncmp(line[0], "echo", 4) == 0)
			ft_echo(1, line);
		else if (line[0] && ft_strncmp(line[0], "cd", 2) == 0)
			ft_cd(line, shell->env);
		else
			printf("%s", inpt);
	}
//	system("leaks minishell");
	return (shell->ret);
}
