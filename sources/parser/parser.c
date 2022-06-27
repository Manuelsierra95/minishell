/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:52:00 by msierra-          #+#    #+#             */
/*   Updated: 2022/06/27 13:02:11 by msierra-         ###   ########.fr       */
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

int	set_type_redir(int type)
{
	int	r_type;

	if (type == T_GREATER)
		r_type = REDIR_OUT;
	else if (type == T_GREATERGREATER)
		r_type = REDIR_APPEND_OUT;
	else if (type == T_LESSER)
		r_type = REDIR_IN;
	else if (type == T_LESSERLESSER)
		r_type = REDIR_HEREDOC;
	else
		r_type = 0;
	return (r_type);
}

t_redir	*add_redir_node(int type, char *value)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	new->r_type = set_type_redir(type);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	create_redir_node(t_redir **redir_list, int type, char *value)
{
	// printf("type: %d\tvalue: %s\n", type, value);
	if (*redir_list)
	{
		while ((*redir_list)->next)
			*redir_list = (*redir_list)->next;
		(*redir_list)->next = add_redir_node(type, value);
	}
	else
		*redir_list = add_redir_node(type, value);
}

t_redir	**get_redir_list(int tok, int index)
{
	t_token	*tokens;
	t_redir	**redir_list;

	tokens = g_shell->tokens;
	redir_list = malloc(sizeof(t_redir*));;
	while (tok < index)
	{
		if (tokens[tok].type == T_GREATER || tokens[tok].type == T_GREATERGREATER 
			|| tokens[tok].type == T_LESSER ||tokens[tok].type == T_LESSERLESSER)
		{
			if (tokens[tok + 1].type == T_TEXT)
				create_redir_node(redir_list, tokens[tok].type, tokens[tok + 1].data);
			else
				mng_errors(NO_FILE_DIR, tokens[tok + 1].data);
		}
		tok++;
	}
	return (redir_list);
}

char	**t_cmd(int tok, int index)
{
	t_token	*tokens;
	char	**cmd;
	int		i;

	i = 0;
	tokens = g_shell->tokens;
	cmd = malloc(sizeof(char *) * (len_of_tokens(tok, index) + 1));
	while (tok < index)
	{
		if (tokens[tok].type == T_GREATER || tokens[tok].type == T_GREATERGREATER
			|| tokens[tok].type == T_LESSER ||tokens[tok].type == T_LESSERLESSER)
			break ;
		if (tokens[tok].type == T_CMD || tokens[tok].type == T_TEXT)
			cmd[i++] = tokens[tok].data;
		tok++;
	}
	cmd[i] = NULL;
	return (cmd);
}

t_tree	*create_node(char **cmd, int n_type, int pos_cmd, t_redir **l_redir)
{
	t_tree	*new;

	new = malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->l_redir = l_redir;
	new->pos_cmd = pos_cmd;
	new->n_type = n_type;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

void	add_node_pipe(t_tree *tree, char **cmd, int pos_cmd, t_redir **l_redir)
{
	if (tree->right)
		add_node_pipe(tree->right, cmd, pos_cmd, l_redir);
    else
		tree->right = create_node(NULL, N_PIPE, pos_cmd, l_redir);
}

void	add_node_cmd(t_tree *tree, char **cmd, int pos_cmd, t_redir **l_redir)
{
	if (tree->left)
		add_node_cmd(tree->left, cmd, pos_cmd, l_redir);
	else
		tree->left = create_node(cmd, N_OTHER, pos_cmd, l_redir);
}

// void	add_value(t_tree *tree, int type, char **cmd, int pos_cmd)
// {
// 	if (type == N_PIPE)
// 	{
// 		if (tree->right)
//             add_value(tree->right, type, cmd, pos_cmd);
//         else
//             tree->right = create_node(NULL, type, pos_cmd);
// 	}
// 	else
// 	{
// 		if (tree->left)
//             add_value(tree->left, type, cmd, pos_cmd);
// 		else
// 			tree->left = create_node(cmd, type, pos_cmd);
// 	}
// }

t_tree	*create_tree()
{
	t_tree	*tree;
	int		index;
	int		tok;
	int		pos_cmd;

	index = -1;
	tree = create_node(NULL, N_PIPE, 0, NULL);
	tok = 0;
	pos_cmd = P_FIRST;
	while (++index < g_shell->numOfArgs)
	{
		// printf("index: %d\tTokens type: %d\t", index, g_shell->tokens[index].type);
		// printf("Data: %s\n", g_shell->tokens[index].data);
		if (g_shell->tokens[index].type == T_PIPE)
		{
			// printf("Va ha crear 2 nodos\n");
			add_node_cmd(tree, t_cmd(tok, index), pos_cmd, get_redir_list(tok, index));
			add_node_pipe(tree, NULL, 0, NULL);
			tok = index;
			pos_cmd = P_MIDDLE;
		}
	}
	pos_cmd = P_LAST;
	add_node_cmd(tree, t_cmd(tok, index), pos_cmd, get_redir_list(tok, index));
	return (tree);
}