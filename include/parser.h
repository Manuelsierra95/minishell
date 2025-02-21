#ifndef PARSER_H
# define PARSER_H

typedef struct s_cmd {
	char **args;
	struct s_cmd *next;
} t_cmd;

typedef struct s_pipeline
{
	t_cmd *cmds;
	struct s_pipeline *next;
}	t_pipeline;

t_pipeline *parser(t_token *tokens);
t_cmd *parse_cmd(t_token *tokens, int *index);
void free_pipeline(t_pipeline *pipeline);

#endif