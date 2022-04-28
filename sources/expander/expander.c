#include "../../includes/minishell.h"

char	*exp_getenv(char *arg, t_list *env)
{
	char	*s;

	s = NULL;
	while (env)
	{
		if (ft_strncmp(env->content, arg, ft_strlen(arg)) == 0)
		{
			s = ft_strdup(env->content);
			break ;
		}
		env = env->next;
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
	if (c_flag == D_QUOTE || c_flag == S_QUOTE)
		flag = 1;
	while (data[++x] != DOLLAR && data[x] != SPACE && x <= (int)ft_strlen(data))
	{
		if (flag == 1)
		{
			if (data[x] == D_QUOTE || data[x] == S_QUOTE)
				break ;
		}
		j++;
	}
	aux_data = ft_substr(data, 1, j + 1);
	$_data = exp_getenv(aux_data, g_shell->env);
	free (aux_data);
	*i = *i + x;
	return ($_data);
}

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
		if (data[i] == DOLLAR)
		{
			aux_data = $_env(&data[i], &i, data[i - 1]);
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
		if (tokens[index].data != NULL && ft_strchr(tokens[index].data, DOLLAR) 
			&& tokens[index].type == 2)
		{
			aux = tokens[index].data;
			tokens[index].data = $_substitute(tokens[index].data, 0);
			free(aux);
		}
		index++;
	}
	return (tokens);
}
