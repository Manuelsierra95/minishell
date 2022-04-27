#ifndef PARSER_H
# define PARSER_H

enum redir_type
{
	REDIR_OUT = 0,
	REDIR_APPEND_OUT,
	REDIR_IN,
	REDIR_HEREDOC,
};

typedef struct s_redir {
	char			*value;
	int				redir_type;
	struct s_redir	*next;
}				t_redir;

typedef struct s_tree
{
	char			**cmd;
	char			*n_data;
	int				n_type;
	struct s_tree	*left;
	struct s_tree	*right;
} t_tree;

#endif
