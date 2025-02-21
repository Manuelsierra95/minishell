#include "minishell.h"

void tokenize_input(const char *input, t_token *token_list) {
	char *copy = ft_strdup(input);
	char *ptr = copy;
	char buffer[1024];
	int buf_index = 0;
	int in_quote = 0;
	char quote_char = '\0';

	while (*ptr && token_list->count < MAX_TOKENS) {
			while (*ptr == ' ' || *ptr == '\t') ptr++;

			if (*ptr == '\0') break;

			buf_index = 0;

			while (*ptr) {
					if ((*ptr == '"' || *ptr == '\'') && (!in_quote || quote_char == *ptr)) {
							if (in_quote) {
									in_quote = 0;
							} else {
									in_quote = 1;
									quote_char = *ptr;
							}
							ptr++; 
							continue;
					}

					if (!in_quote && (*ptr == ' ' || *ptr == '\t')) break;

					buffer[buf_index++] = *ptr;
					ptr++;
			}

			buffer[buf_index] = '\0';

			if (buf_index > 0) {
					token_list->value[token_list->count++] = ft_strdup(buffer);
			}
	}

	free(copy);
}

void free_tokens(t_token *token_list) {
	int i;

	i = 0;
	while (i < token_list->count) {
			free(token_list->value[i]);
			i++;
	}
	free(token_list);
}