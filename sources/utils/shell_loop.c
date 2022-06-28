#include "minishell.h"

void inorden(t_tree *tree)
{
	if (tree != NULL)
	{
		if (tree->n_type != N_PIPE)
		{
		/*	t_redir **redir_list;
			redir_list = tree->l_redir;
			if (tree->l_redir)
				while (*redir_list)
				{
					printf("l_redir: %s\tType: %d\n", (*redir_list)->value, (*redir_list)->r_type);
					*redir_list = (*redir_list)->next;
				}*/

			if (g_shell->numOfPipes == 0)
				exe_single_child(tree, 1);
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
