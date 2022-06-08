#include "echo.h"

void	*get_echo()
{
	t_echo	*echo;

	echo = malloc(sizeof(t_echo));
	echo->arg = g_shell->arg;
	echo->fd = g_shell->fd;
	return (echo);
}
