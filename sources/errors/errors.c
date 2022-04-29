#include "../../includes/minishell.h"

void	mng_errors(int flag, char *data)
{
	if (flag == CMD_NOT_FOUND)
		printf("bash: %s: command not found", data);
	if (flag == NO_FILE_DIR)
		printf("bash: %s: No such file or directory", data);
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
		index++;
	}
	if (flag != 0)
			mng_errors(flag, tokens[0].data);
	return (flag);
}
