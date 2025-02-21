#include "minishell.h"

t_cmd *parse_cmd(t_token *tokens, int *index) {
	t_cmd *cmd;
	int arg_index;

	cmd = malloc(sizeof(t_cmd));
	cmd->args = malloc(sizeof(char *) * (tokens->count + 1));
	arg_index = 0;
	while (tokens->value[*index] && ft_strcmp(tokens->value[*index], "|") != 0) {
		cmd->args[arg_index++] = ft_strdup(tokens->value[*index]);
		(*index)++;
	}
	cmd->args[arg_index] = NULL;
	cmd->next = NULL;
	return cmd;
}

void free_pipeline(t_pipeline *pipeline) {
	t_cmd *cmd;
	t_cmd *tmp;
	int i;

	cmd = pipeline->cmds;
	i = 0;
	while (cmd) {
		while (cmd->args[i] != NULL) {
			free(cmd->args[i]);
			i++;
		}
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
	free(pipeline);
}