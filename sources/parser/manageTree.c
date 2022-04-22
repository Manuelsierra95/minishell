#include "../../includes/minishell.h"

t_tree	*create_node(t_tree *node, char *data)
{
	t_tree	*new;

	new = malloc(sizeof(t_tree));
	new->data = data;
	new->node = node;
	return (new);
}

t_tree	add_value(t_tree *tree, t_token token)
{
	t_token	*temp;
	t_token	*pivot;

	if (token.type == PIPE)
	//ramificamos derecha
	{
		
	}
	else
	// ramificamos izquierda
	{

	}
}

t_tree	create_tree()
{
	t_tree	*tree;
	int		index;

	index = -1;
	tree = NULL;
	while (++index < g_shell->numOfArgs)
	{
		add_value(tree, g_shell->tokens[index]);
	}
	
}
