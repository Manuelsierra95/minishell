#include "minishell.h"

t_token *lexer(char *input) {
	t_token *tokens = ft_calloc(1, sizeof(t_token));

	tokenize_input(input, tokens);

	// free_tokens(tokens);
	return (tokens);
}