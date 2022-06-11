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

enum pos_cmd
{
	P_FIRST = 1,
	P_MIDDLE,
	P_LAST,
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
	t_redir			*l_redir;
	int				n_type;
	int				pos_cmd;
	struct s_tree	*right;
	struct s_tree	*left;
} t_tree;


t_tree	*create_tree();

#endif