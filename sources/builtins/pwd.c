#include "minishell.h"

int	ft_pwd(void)
{
	char	buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX))
	{
		ft_putendl_fd(buf, 1);
		return (0);
	}
	return (1);
}
