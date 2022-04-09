#include "minishell.h"

void	ft_exit(char **argv, t_shell *shell)
{
	shell->exit = 1;
	ft_putstr_fd("exit", STDERR);
	if (argv[1] && argv[2])
	{
		shell->ret = 1;
		ft_putendl_fd("minishell: exit: too many arguments", STDERR);
	}
	else if (argv[1] && !ft_isnum(argv[1]))
	{
		shell->ret = 2;
		ft_putstr_fd("minishell: exit", STDERR);
		ft_putstr_fd(argv[1], STDERR);
		ft_putendl_fd(": numeric argument required", STDERR);
	}
	else if (argv[1])
		shell->ret = ft_atoi(argv[1]) % 256;
	else
		shell->ret = 0;
}
