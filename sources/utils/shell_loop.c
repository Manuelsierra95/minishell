#include "minishell.h"

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
