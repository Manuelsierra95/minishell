#include "minishell.h"

static int	print_error(char *arg)
{
	char	*err_msg;

	err_msg = ft_strjoin("`", arg);
	err_msg = ft_strjoin(err_msg, "'");
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	free(err_msg);
	return (1);
}

int	is_valid(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
		return (-1);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (-1);
		i++;
	}
	if (arg[i] && arg[i] == '=')
		return (1);
	return (0);
}

int	is_in_env(char *arg, int ret)
{
	if (ret == 1 && name_in_env(arg, g_shell->env))
	{
		if (value_in_env(arg, g_shell->env))
			return (1);
		else
			return (0);
	}
	else if (ret == 0 && name_in_env(arg, g_shell->secret))
		return (1);
	return (0);
}

int	ft_export(char **arg)
{
	int	i;
	int	ret;
	int n;

	i = 1;
	if (!arg[i])
		return (print_secret(g_shell->secret));
	while (arg[i])
	{
		ret = is_valid(arg[i]);
		if (ret == -1)
			return (print_error(arg[i]));
		n = is_in_env(arg[i], ret)
		if (n == 0)
		{
			if (ret == 1)
				//env_add(arg[i], g_shell->env);
			//env_add(arg[i], g_shell->secret);
		}
		i++;
	}
	return (0);
}
