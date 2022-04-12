#include "minishell.h"

int	ft_cd(char **arg, t_env *env)
{
	int	ret;

	ret = chdir(arg[1]);
	(void) env;
	return (ret);
}
