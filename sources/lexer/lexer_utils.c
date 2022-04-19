#include "../../includes/minishell.h"

char *r_special(int type)
{
	// printf("Type special: %d\n", type);
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
	// printf("state: %c\n", state);
	if (input[x + 1] == state)
		x++;
	else // TODO: Arreglar segv echo """ (con 3 comillas)
	{
		// printf("Entra\n");
		x++;
		start = x;
		while (input[x] != state)
			x++;
		if (s_isspecial(ft_substr(input, start, x)[0]))
			split_input = ft_substr(input, start - 1, x + 1);
		else
			split_input = ft_substr(input, start, x);
		// printf("Sale valiendo: %c\n", input[x]);
		// printf("lo que splitea: %s\n", ft_substr(input, start, x));
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
	{
		split_input = input_line2(input, &x);
	}
	if (state == CHAR)
	{
		start = x;
		while (ft_isalpha_edit(input[x]))
			x++;
		split_input = ft_substr(input, start, x);
		x--;
	}
	if (state != 0 && (state == D_QUOTE || state == S_QUOTE))
	{
		split_input = input_line3(input, state, &x, start);
	}
	*i = x;
	return (split_input);
}

char **split_loop(t_shell *shell, char *input)
{
	int i;
	int start;
	int state;
	char **split_input;
	char	*aux;

	i = -1;
	state = 0;
	start = 0;
	split_input = malloc(1024);
	while (input[++i])
	{
		// printf("loo_input[%d]: %c\n", i, input[i]);
		if (input[i] == SPACE)
			i++;
		state = input_state(input[i]);
		aux = input_line(input, state, &i, start);
		if (aux)
			split_input[shell->index++] = aux;
	}
	split_input[shell->index++] = NULL;
	return (split_input);
}

int input_len(char **input)
{
	int size;
	int i;

	i = -1;
	size = 0;
	while (input[++i])
	{
		// if (input[i] != NULL || input[i][0] != '\0')
			size++;
	}
	return (size);
}

char **split_input(t_shell *shell, char *input)
{
	char **aux;

	aux = split_loop(shell, input);
	int l = 0;
	while (l < shell->index)
	{
		printf("split_input[%d]: %s\n", l, aux[l]);
		l++;
	}

	return (aux);
}

// char	*take_off_spaces(char *input)
// {
// 	int		i;
// 	int		x;
// 	int		state;
// 	char	*aux_input;

// 	i = -1;
// 	x = 0;
// 	state = 0;
// 	printf("Input_off_spaces: %s\n", input);
// 	aux_input = malloc(sizeof(char *));
// 	while (input[++i])
// 	{
// 		printf("Input[%d]: %c\n", i, input[i]);
// 		if (input[i] == D_QUOTE)
// 		{
// 			if (state == 0)
// 				state = 1;
// 			else
// 				state = 0;
// 		}
// 		if (state == 1)
// 			aux_input[x++] = input[i];
// 		if (state == 0 && i > 0)
// 			break ;
// 		printf("Aux_input: %s\n", aux_input);
// 	}
// 	aux_input[x++] = '\0';
// 	printf("Input_off_spaces: %s\n", aux_input);
// 	return (aux_input);
// }
