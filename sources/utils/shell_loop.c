#include "minishell.h"

void	*shell_cmds(char **cmd)
{
	t_value		*exec;
	void		*get_arg;

	if (get(g_shell->map, cmd[0]))
	{
		printf("Ejecuta el builtin\n");
		g_shell->arg = cmd;
		exec = get(g_shell->map, cmd[0]);
		get_arg = exec->get_arg();
		exec->function(get_arg);
		free(get_arg);	// Ejecutar despues de cada exec
	}
	else
		printf("Ejecutara el executor\n");
	return (NULL);
}

void inorden(t_tree *tree)
{
	if (tree != NULL)
	{
		if (tree->n_type != N_PIPE)
		{
			// shell_cmds(tree->cmd);
			exe_pipes(tree, g_shell);
		}
        inorden(tree->left);
        inorden(tree->right);
    }
}

void	shell_loop()
{
	inorden(g_shell->tree);
}
