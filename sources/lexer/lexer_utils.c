#include "../../includes/minishell.h"

char *r_special(int type)
{
	if (type == T_PIPE)
		return ("|");
	else if (type == T_GREATER)
		return (">");
	else if (type == T_LESSER)
		return ("<");
	else if (type == T_GREATERGREATER)
		return (">>");
	else if (type == T_LESSERLESSER)
		return ("<<");
	return (NULL);
}

int input_state(char input)
{
	int state;

	if (input == D_QUOTE)
		state = D_QUOTE;
	if (input == S_QUOTE)
		state = S_QUOTE;
	if (ft_isalpha_edit(input))
		state = CHAR;
	if (s_isspecial(input))
		state = s_isspecial(input);
	return (state);
}

char *input_line2(char *input, int *i)
{
	char *split_input;
	int	x;

	x = *i;
	if (s_isspecial(input[x + 1]))
	{
		split_input = ft_strdup(r_special(d_isspecial(input[x], input[x + 1])));
		x += 2;
	}
	else
		split_input = ft_strdup(r_special(s_isspecial(input[x])));
	*i = x;
	return (split_input);
}

char *input_line3(char *input, int state, int *i, int start)
{
	char *split_input;
	int	x;

	x = *i;
	split_input = NULL;
	if (input[x + 1] == state)
		x++;
	else
	{
		x++;
		start = x;
		while (input[x] != state)
			x++;
		if (s_isspecial(ft_substr(input, start, x)[0]))
			split_input = ft_substr(input, start - 1, x + 1);
		else
			split_input = ft_substr(input, start, x);
	}
	*i = x;
	return (split_input);
}

char *input_line(char *input, int state, int *i, int start)
{
	char *split_input;
	int	x;

	x = *i;
	if (s_isspecial(input[x]))
		split_input = input_line2(input, &x);
	if (state == CHAR)
	{
		start = x;
		while (ft_isalpha_edit(input[x]))
			x++;
		split_input = ft_substr(input, start, x);
		x--;
	}
	if (state != 0 && (state == D_QUOTE || state == S_QUOTE))
		split_input = input_line3(input, state, &x, start);
	*i = x;
	return (split_input);
}

char **split_loop(char *input, char **split_input, int state)
{
	int i;
	int start;
	char	*aux;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (input[i] == SPACE)
			i++;
		state = input_state(input[i]);
		aux = input_line(input, state, &i, start);
		if (aux)
			split_input[g_shell->index++] = aux;
	}
	split_input[g_shell->index] = NULL;
	return (split_input);
}

int	get_matrix_size(char *input, int state)
{
	int		size;
	int		start;
	int		i;
	char	*aux;

	i = 0;
	start = 0;
	size = 0;
	while (input[++i])
	{
		if (input[i] == SPACE)
			i++;
		state = input_state(input[i]);
		aux = input_line(input, state, &i, start);
		if (aux)
			size++;
	}
	free(aux);
	return (size);
}

char **split_input(char *input) //TODO: free a la matriz
{
	char **split_input;
	int		size;

	size = get_matrix_size(input, 0);
	split_input = malloc(sizeof(char *) * (size + 1));
	split_input = split_loop(input, split_input, 0);

	return (split_input);
}
