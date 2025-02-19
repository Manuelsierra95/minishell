/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/19 21:35:21 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	init_shell();

	char	*inpt;

	while(g_shell->exit == 0) {
		inpt = readline("minishell> ");
		add_history(inpt);
		if (ft_strcmp(inpt, "exit") == 0) 
			g_shell->exit = 1;
		printf("%s\n", inpt);
		// Aqui llamaremos al parser
		// parser(inpt);
		// Aqui llamaremos al executor
		// executor();
	}

	free_shell();
	free(inpt);

	return (0);
}