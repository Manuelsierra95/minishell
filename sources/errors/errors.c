#include "minishell.h"

void	mng_errors(int flag, char *data)
{
	if (flag == NO_FILE_DIR)
		printf("bash: %s: No such file or directory\n", data);
	else if (flag == PIPE_UNEXPECTED)
		printf("bash: syntax error near unexpected token `|'\n");
	else if (flag == GREAT_LESSER_UNEXPECTED)
		printf("bash: syntax error near unexpected token `newline'\n");
	else if (flag == QUOTE_ERROR)
		printf("insufficient number of quotes\n");
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
		// if (ft_strchr(tokens[0].data, '/'))
		// 	flag = NO_FILE_DIR;
		if (tokens[0].type == T_PIPE)
			flag = PIPE_UNEXPECTED;
		index++;
	}
	if (flag != 0)
			mng_errors(flag, tokens[0].data);
	return (flag);
}
