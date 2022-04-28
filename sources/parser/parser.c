#include "../../includes/minishell.h"

int	len_of_tokens(int tok, int index)
{
	t_token	*tokens;
	int	size;

	size = 0;
	tokens = g_shell->tokens;
	while (tok < index)
	{
		if (tokens[tok].type == T_CMD)
			size++;
		tok++;
	}
	return (size);
}

char	**t_cmd(int tok, int index)
{
	t_token	*tokens;
	char	**cmd;
	int		i;

	i = 0;
	tokens = g_shell->tokens;
	cmd = malloc(sizeof(char *) * (len_of_tokens(tok, index) + 1));
	// printf("size malloc: %lu\n", (sizeof(char *) * (len_of_tokens(tok, index) + 1)));
	while (tok < index)
	{
		if (tokens[tok].type == T_CMD)
			cmd[i++] = ft_strdup(tokens[tok].data);
		tok++;
	}
	cmd[i] = NULL;
	return (cmd);
}

char	*t_data(int tok, int index)
{
	t_token	*tokens;
	char	*data;

	tokens = g_shell->tokens;
	data = NULL;
	while (tok < index)
	{
		if (tokens[tok].type == T_TEXT)
			data = ft_strdup(tokens[tok].data);
		tok++;
	}
	return (data);
}

t_tree	*create_node(char **cmd, char *data, int type)
{
	t_tree	*new;

	new = malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	// printf("data: %s\ncmd[0]: %s\ncmd[1]: %s\n", data, cmd[0], cmd[1]);
	new->n_data = data;
	new->cmd = cmd;
	new->n_type = type;
	new->right = NULL;
	new->left = NULL;

	return (new);
}

void	add_value(t_tree *tree, int type, char **cmd, char *data)
{
	// printf("type: %d\n", type);
	// printf("data: %s\ncmd[0]: %s\ncmd[1]: %s\n", data, cmd[0], cmd[1]);
	if (type == N_PIPE)
	{
		// printf("Entra\n");
		if (tree->right)
            add_value(tree->right, type, cmd, data);
        else
            tree->right = create_node(NULL, NULL, type);
		// printf("Sale\n");
	}
	else
	{
		if (tree->left)
            add_value(tree->left, type, cmd, data);
		else
			tree->left = create_node(cmd, data, type);
	}
}

t_tree	*create_tree()
{
	t_tree	*tree;
	int		index;
	int		tok;

	index = -1;
	tree = create_node(NULL, NULL, N_PIPE);
	tok = 0;
	while (++index < g_shell->numOfArgs) //Si no hay pipes, hacer que haya 1 stack
	{
		if (g_shell->tokens[index].type == T_PIPE)
		{
			add_value(tree, N_OTHER, t_cmd(tok, index), t_data(tok, index));
			add_value(tree, N_PIPE, NULL, NULL);
			tok = index;
		}
	}
	add_value(tree, 0, t_cmd(tok, index), t_data(tok, index));
	return (tree);
}
