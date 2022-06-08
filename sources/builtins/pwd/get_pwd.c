#include "pwd.h"
#include "minishell.h"

void	*get_pwd()
{
	t_pwd	*pwd;

	pwd = malloc(sizeof(t_pwd));
	pwd->fd = g_shell->fd;
	return (pwd);
}
