#include "minishell.h"

void	mng_errors(int flag, char *data)
{
	if (flag == CMD_NOT_FOUND)
		printf("bash: %s: command not found", data);
	else if (flag == NO_FILE_DIR)
		printf("bash: %s: No such file or directory", data);
	else if (flag == PIPE_UNEXPECTED)
		printf("bash: syntax error near unexpected token `|'");
	else if (flag == GREAT_LESSER_UNEXPECTED)
		printf("bash: syntax error near unexpected token `newline'");
	else if (flag == QUOTE_ERROR)
		printf("insufficient number of quotes");
	
	exit(0);
}

int	check_for_errors(t_token *tokens)// Pensar bien el tema de errores!!!
{
	int	index;
	int	size;
	int	flag;

	flag = 0;
	index = 0;
	size = g_shell->numOfArgs;
	while (index < size && flag == 0) // Hacer que exit y demas no los trate como error
	{
		// printf("data: %s\n", tokens[0].data);
		if (tokens[0].type != T_CMD && !(ft_strchr(tokens[0].data, '/')))
			flag = CMD_NOT_FOUND;
		else if (ft_strchr(tokens[0].data, '/'))
			flag = NO_FILE_DIR;
		else if (tokens[0].type == T_PIPE)
			flag = PIPE_UNEXPECTED;
		else if (tokens[0].type == T_GREATER || tokens[0].type == T_GREATERGREATER
				|| tokens[0].type == T_LESSER || tokens[0].type == T_LESSERLESSER)
			flag = GREAT_LESSER_UNEXPECTED;
		index++;
	}
	if (flag != 0)
			mng_errors(flag, tokens[0].data);
	return (flag);
}
