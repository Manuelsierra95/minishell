/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:52:00 by msierra-          #+#    #+#             */
/*   Updated: 2022/06/09 12:30:14 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_of_tokens(int tok, int index)
{
	t_token	*tokens;
	int	size;

	size = 0;
	tokens = g_shell->tokens;
	while (tok < index)
	{
		if (tokens[tok].type == T_CMD || tokens[tok].type == T_TEXT)
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
	while (tok < index + 1)
	{
		if (tokens[tok].type == T_CMD || tokens[tok].type == T_TEXT)
			cmd[i++] = tokens[tok].data;
		tok++;
	}
	cmd[i] = NULL;
	return (cmd);
}

t_tree	*create_node(char **cmd, int type)
{
	t_tree	*new;

	new = malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->n_type = type;
	new->right = NULL;
	new->left = NULL;

	return (new);
}

void	add_value(t_tree *tree, int type, char **cmd)
{
	if (type == N_PIPE)
	{
		if (tree->right)
            add_value(tree->right, type, cmd);
        else
            tree->right = create_node(NULL, type);
	}
	else
	{
		if (tree->left)
            add_value(tree->left, type, cmd);
		else
			tree->left = create_node(cmd, type);
	}
}

t_tree	*create_tree()
{
	t_tree	*tree;
	int		index;
	int		tok;

	index = -1;
	tree = create_node(NULL, N_PIPE);
	tok = 0;
	tree->pos_cmd = P_FIRST;
	while (++index < g_shell->numOfArgs)
	{
		if (g_shell->tokens[index].type == T_PIPE || (index + 1) == g_shell->numOfArgs)
		{
			if ((index + 1) == g_shell->numOfArgs)
				tree->pos_cmd = P_LAST;
			add_value(tree, N_OTHER, t_cmd(tok, index));
			add_value(tree, N_PIPE, NULL);
			tok = index;
			tree->pos_cmd = P_MIDDLE;
		}
	}
	return (tree);
}