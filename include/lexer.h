#ifndef LEXER_H
# define LEXER_H

# define MAX_TOKENS 100

typedef struct s_token
{
	char	*value[MAX_TOKENS];
	int 	count;
}	t_token;

t_token *lexer(char *str);
void tokenize_input(const char *input, t_token *token_list);
void free_tokens(t_token *token_list);

#endif