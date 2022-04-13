/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/13 17:13:41 by mbarylak         ###   ########.fr       */
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

// int	main(int argc, char **argv, char **env)
// {
// 	char	*inpt;
// 	char	**line;
// 	t_shell	*shell;

// 	(void) argc;
// 	(void) argv;
// 	shell = init_shell();
// 	env_to_shell(env, shell);
// 	while (shell->exit == 1)
// 	{
// 		inpt = readline("minishell> ");
// 		add_history(inpt);
// 		line = ft_split(inpt, ' ');
// 		if (ft_strncmp(line[0], "pwd", 3) == 0)
// 			ft_pwd();
// 		else if (ft_strncmp(line[0], "exit", 4) == 0)
// 			ft_exit(line, shell);
// 		else if (ft_strncmp(line[0], "env", 3) == 0)
// 			ft_env(shell->env);
// 		else if (ft_strncmp(line[0], "echo", 4) == 0)
// 			ft_echo(line);
// 		else if (ft_strncmp(line[0], "cd", 2) == 0)
// 			ft_cd(line, shell->env);
// 		else
// 			printf("%s\n", inpt);
// 	}
// //	system("leaks minishell");
// 	return (shell->ret);
// }

int main(int argc, char **argv, char **env)
{
	t_token 	*tokens;
	t_shell		*dataInfo;

	dataInfo = malloc(sizeof(t_shell));

	get_path(dataInfo, env);

	tokens = lexer(dataInfo, argc, argv);
	dataInfo->tokens = tokens;

	int index = 0;
	char *s = tokens[0].data;
	printf("index[0]: %s\n", s);
	while (index < dataInfo->numOfArgs)
	{
		printf("Index: %d\tType: %d\tData: %s\n", index, dataInfo->tokens[index].type, dataInfo->tokens[index].data);
		index++;
	}
	

	// while (aux)
	// {
	// 	printf("Type: %d\tData: %s\n", aux->type, aux->data);
	// 	aux = aux->next;
	// }

}
