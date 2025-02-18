/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:58:14 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	char	*inpt;

	while(1) {
		inpt = readline("minishell> ");
		add_history(inpt);
		printf("%s\n", inpt);
	}

	return (0);
}