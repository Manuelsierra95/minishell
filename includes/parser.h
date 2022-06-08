#ifndef PARSER_H
# define PARSER_H

#include"interface.h"

enum redir_type
{
	REDIR_OUT = 1,
	REDIR_APPEND_OUT,
	REDIR_IN,
	REDIR_HEREDOC,
};

enum node_type
{
	N_PIPE = 1,
	N_OTHER,
};

// Tree
typedef struct s_redir {
	char			*value;
	int				r_type;
	struct s_redir	*next;
} t_redir;

typedef struct s_tree
{
	char			**cmd;
	int				n_type; // 1 -> PIPE // 2 -> OTHER
	t_redir			*l_redir;
	struct s_tree	*right;
	struct s_tree	*left;
} t_tree;


t_tree	*create_tree();

#endif