#include "../../includes/minishell.h"


void	shell_cmds(char *inpt, char **line) // Input = todo en un doble puntero (Data incluida)
{
	// printf("input: %s\n", inpt);
	// printf("line[0]: %s\n", line[0]);
	// printf("num: %d\n", ft_strcmp(line[0], "echo"));
	// printf("num2: %d\n", ft_strcmp(line[0], "\n"));

	// if (inpt != NULL || ft_strcmp(inpt, "\n") == 0)	// No se porque (inpt != NULL) falla con eso
	// 	line = ft_split(inpt, ' ');
	if (line[0] && ft_strcmp(line[0], "pwd") == 0)
		ft_pwd(1);
	else if (line[0] && ft_strcmp(line[0], "exit") == 0)
		ft_exit(line, g_shell);
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

void inorden(t_tree *tree) {
	if (tree != NULL)
	{
		if (tree->n_type != N_PIPE)
		{
			// shell_cmds(tree->cmd);
			int i = 0;
			while (tree->cmd[i])
			{
    			printf("cmd[%d]: %s\n", i, tree->cmd[i]);
				i++;
			}
		}
        inorden(tree->left);
        inorden(tree->right);
    }
}

void	shell_loop()
{
	// TODO: mejorar el arbol porque solo pilla en el loop una data en caso de que haya mas
	printf("PIpes: %d\n", g_shell->numOfPipes);
	inorden(g_shell->tree);
}
