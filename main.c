/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/14 11:23:16 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(char **env)
{
	g_shell = malloc(sizeof(t_shell));
	g_shell->exit = 1;
	g_shell->ret = 0;
	g_shell->exit_stat = 0;
	g_shell->fd[0] = 0;
	g_shell->fd[1] = 1;
	put_builtins(g_shell->map);
	env_to_shell(env);
	secret_to_shell(env);
}

void	ft_free(char *inpt, char **line)
{
	free_arr(line);
	ft_memdel(inpt);
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

int	main(int argc, char **argv, char **env)//TODO: Cambiar campos de los getters
{
	char	*inpt;
	char	**line;
	int		flag;

	(void) argc;
	(void) argv;
	init_shell(env);
	get_path();
	while (g_shell->exit == 1)
	{
		inpt = readline(CYAN "minishell> " RESET);
		add_history(inpt);
		check_quote_error(inpt);
		flag = 0;
		g_shell->numOfArgs = 0;
		g_shell->numOfPipes = 0;
		g_shell->index = 0;
		if (ft_strchr(inpt, '$'))
			flag = 1;
		line = split_input(inpt);
		if (line)
		{
			g_shell->tokens = lexer(line);
			if (!check_for_errors(g_shell->tokens))
			{
				if (flag == 1)
					g_shell->tokens = expander(g_shell->tokens);
				g_shell->tree = create_tree();
				shell_loop();
			}
		// free_matrix(line);
		// free(g_shell->tokens);
			// while (index < g_shell->numOfArgs)
			// int index = 0;
		}
	}
	clean_map(g_shell->map);
	return (g_shell->ret);
}

/* Cositas a cambiar 

	++Quitar la gestión de error de cmd not found, ya la gestiono yo.
	++Arreglar el segfault que da split_input cuando el inpt es salto de linea.
	++Unset no lo detecta correctamente el mapa, o lo que sea.
	++Export no recibe bien los argumentos, quitar split por '='.
	De hecho parece que haces split con todo lo que no son letras, solo hazlo de espacios y pipes.
	La ejecución de pipes da muchos errores muy raros con builtins todavia.
*/
