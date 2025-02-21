#include "minishell.h"

void executor(t_pipeline *pipeline) {
	int i;

	while (pipeline != NULL) {
		printf("Pipeline:\n");
		t_cmd *cmd = pipeline->cmds;
		while (cmd != NULL) {
			printf("  Command:\n");
			i = 0;
			while (cmd->args[i] != NULL) {
				printf("    Arg %d: %s\n", i + 1, cmd->args[i]);
				i++;
			}
			cmd = cmd->next;
		}
		pipeline = pipeline->next;
	}
}