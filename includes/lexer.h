#ifndef LEXER_H
# define LEXER_H

enum char_type
{
	CHAR = -1,
	DOLLAR = '$',
	PIPE = '|',
	GREATER = '>',
	LESSER = '<',
	SPACE = 32,
	S_QUOTE = 39, // Comilla simple
	D_QUOTE = '"', // Comilla doble
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


int		check_cmd(char *input);
int		ft_isalpha(int c);
int		d_isspecial(int c, int d);
int		s_isspecial(int c);
char	*take_off_quotes(char *input);
int		check_quotes(char *input);
#endif