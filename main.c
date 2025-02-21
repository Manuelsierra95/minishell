/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/21 21:49:54 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*inpt;
	t_token	*tokens;
	t_pipeline	*pipeline;

	init_shell();


	while(g_shell->exit == 0) {
		inpt = readline("minishell> ");
		add_history(inpt);
		if (ft_strcmp(inpt, "exit") == 0) 
			g_shell->exit = 1;
		tokens = lexer(inpt);
		pipeline = parser(tokens);
		executor(pipeline);
	}

	free_tokens(tokens);
	free_pipeline(pipeline);
	free_shell();
	free(inpt);

	return (0);
}