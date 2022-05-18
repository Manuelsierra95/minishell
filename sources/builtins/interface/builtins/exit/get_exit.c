#include "exit.h"

void	get_exit()
{
	t_exit	*exit;

	exit = malloc(sizeof(t_exit));
	exit->arg = g_shell->arg;
	exit->shell = g_shell->shell;
	return (exit);
}
