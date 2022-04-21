#include "../../includes/minishell.h"


// char	*check_$_in_env(char *aux_data)
// {
// 	int		i;
// 	char	$_data;

// 	i = -1;
// 	$_data = NULL;
// 	while (g_shell->env[++i])
// 	{
// 		if (ft_strncmp(g_shell->env[i], aux_data, ft_strlen(aux_data)))
// 		{
// 			$_data = ft_getenv("=", );
// 		}
// 	}
// 	return ($_data);
// }

char	*ft_getenv(char *arg, char **env)
{
	char	*s;
	int		i;

	s = NULL;
	i = -1;
	// printf("data que entra: %s\n", arg);
	while (env[++i])
	{
		if (ft_strncmp(env[i], arg, ft_strlen(arg)) == 0)
		{
			s = ft_strdup(env[i]);
			break ;
		}
	}
	if (s == NULL)
		return (NULL);
	else
		return (ft_strchr_jump(s, '='));
}

char	*$_env(char *data, int *i, char c_flag)
{
	int		x;
	int		j;
	char	*aux_data;
	char	*$_data;
	int		flag;

	x = 0;
	j = 0;
	flag = 0;
	printf("data que entra: %s\n", data);
	// printf("valor de x: %d\n", x);
	// printf("strlen: %zu\n", ft_strlen(data));
	if (c_flag == D_QUOTE || c_flag == S_QUOTE)
		flag = 1;
	while (data[++x] != '$' && data[x] != SPACE && x <= (int)ft_strlen(data))
	{
		if (flag == 1)
		{
			if (data[x] == D_QUOTE || data[x] == S_QUOTE)
				break ;
		}
		printf("data[%d]: %c\n", x, data[x]);
		// x++;
		j++;
	}
	// printf("valor de start: %d\tvalor de j: %d\n", start, j);
	aux_data = ft_substr(data, 1, j + 1);

	$_data = ft_getenv(aux_data, g_shell->envv);
	// printf("$_data: %s\n", $_data);
	*i = *i + x;
	return ($_data);
}

// int	size_of_exp(char *data)
// {
// 	int	i;
// 	int	size;
// 	int	len;

// 	i = 0;
// 	size = 0;
// 	len = (int) ft_strlen(data);
// 	printf("strlen de input: %d\n", len);
// 	while (data[i])
// 	{
// 		if (data[i++] == '$')
// 		{
// 			printf("Data antes del loop: %c\n", data[i]);
// 			while (data[i] != '$')
// 			{
// 				printf("data[%d]: %c\n", i, data[i]);
// 				i++;
// 				size++;
// 			}
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (size + 1);
// }

char	*$_substitute(char *data, int index)
{
	char	*aux_data;
	char	*exp_data;
	int		i;
	int		j;

	i = -1;
	exp_data = malloc(SET_MEMORY);
	while (data[++i])
	{
		if (data[i] == '$')
		{
			aux_data = $_env(ft_substr(data, i, ft_strlen(data)), &i, data[i - 1]);
			if (aux_data)
			{
				j = 0;
				while (aux_data[j] && j < (int)ft_strlen(aux_data))
					exp_data[index++] = aux_data[j++];
			}
			i--;
		}
		else
			exp_data[index++] = data[i];
	}
	return (exp_data);
}

t_token	*expander(t_token *tokens)
{
	int		index;
	char	*aux;

	index = 0;
	while (index < g_shell->numOfArgs)
	{
		if (ft_strchr(tokens[index].data, '$'))
		{
			// printf("data: %s\n", $_substitute(tokens[index].data));
			aux = tokens[index].data;
			tokens[index].data = $_substitute(tokens[index].data, 0);
			free(aux);
		}
		index++;
	}
	return (tokens);
}
