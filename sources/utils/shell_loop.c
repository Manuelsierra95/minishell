#include "minishell.h"

void inorden(t_tree *tree)
{
	if (tree != NULL)
	{
		if (tree->n_type != N_PIPE)
		{
			if (g_shell->numOfPipes == 0)
				redir_loop(tree);
			else
				exe_pipes(tree);
		}
		inorden(tree->left);
		inorden(tree->right);
	}
}

void	shell_loop()
{
	inorden(g_shell->tree);
}
