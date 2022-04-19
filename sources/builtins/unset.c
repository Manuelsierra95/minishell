#include "minishell.h"

static void	print_error(char *arg)
{
	char	*err_msg;

	err_msg = ft_strjoin("`", arg);
	err_msg = ft_strjoin(err_msg, "'");
	ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	ft_memdel(err_msg);
}

int	ft_unset(char **arg)
{
	t_list	*env;
	t_list	*aux;
	int		i;

	env = g_shell->env;
	if (!arg[1])
		return (0);
	i = 1;
	while (arg[i])
	{
		if (is_valid(arg[i]) == -1)
			print_error(arg[i]);
		i++;
	}
}
