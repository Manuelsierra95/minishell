/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/22 19:31:12 by mbarylak         ###   ########.fr       */
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
		{	
			line = ft_split(inpt, ' ');
			ft_memdel(inpt);
		}
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
			printf("%s\n", env_2_str(g_shell->secret));
		else if (line[0] && ft_strcmp(line[0], "unset") == 0)
			ft_unset(line);
		else
			printf("%s", inpt);
		free_arr(line);
	}
//	system("leaks minishell");
	return (g_shell->ret);
}
