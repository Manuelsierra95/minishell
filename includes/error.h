#ifndef ERROR_H
# define ERROR_H

enum error_flag
{
	CMD_NOT_FOUND = 1,
	NO_FILE_DIR,
	PIPE_UNEXPECTED,
	GREAT_LESSER_UNEXPECTED,
	QUOTE_ERROR,
};

void	mng_errors(int flag, char *data);
int	check_for_errors(t_token *tokens);

#endif