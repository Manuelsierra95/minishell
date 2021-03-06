#ifndef LEXER_H
# define LEXER_H

enum char_type
{
	CHAR = 1,
	DOLLAR = '$',
	PIPE = '|',
	GREATER = '>',
	LESSER = '<',
	SPACE = 32,
	S_QUOTE = 39,
	D_QUOTE = '"',
};

enum token_type
{
	T_CMD = 1,
	T_TEXT,
	T_PIPE,
	T_GREATER,
	T_GREATERGREATER,
	T_LESSER,
	T_LESSERLESSER,
};

typedef struct s_token
{
	int				type;
	char			*data;
} t_token;


int		check_access(char *input);
void	get_path(void);
char 	**split_input(char *input);
t_token	*lexer(char **input);
int		quote_analyzer(char *input);
int		check_cmd(char *input);
int		ft_isalpha(int c);
int		d_isspecial(int c, int d);
int		s_isspecial(int c);
char	*take_off_quotes(char *input);
int		check_quotes(char *input);
int		count_quotes(char *input);
int		input_state(char input);

#endif