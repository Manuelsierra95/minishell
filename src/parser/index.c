#include "minishell.h"

t_pipeline *parser(t_token *tokens) {
	t_pipeline *pipeline = malloc(sizeof(t_pipeline)); 
	pipeline->cmds = NULL;
	pipeline->next = NULL;
	t_pipeline *current_pipeline = pipeline;
	
	int i = 0;
	while(i < tokens->count) {
		if (ft_strcmp(tokens->value[i], "|") == 0) {
			t_pipeline *new_pipeline = malloc(sizeof(t_pipeline));
			new_pipeline->cmds = NULL;
			new_pipeline->next = NULL;
	
			current_pipeline->next = new_pipeline;
			current_pipeline = new_pipeline;
			i++;
			continue;
		}

		t_cmd *new_cmd = parse_cmd(tokens, &i);
		
		if (current_pipeline->cmds == NULL) {
			current_pipeline->cmds = new_cmd;
		} else {
			t_cmd *last_cmd = current_pipeline->cmds;
			while (last_cmd->next) {
				last_cmd = last_cmd->next;
			}
			last_cmd->next = new_cmd;
		}
	}

	return pipeline;
}