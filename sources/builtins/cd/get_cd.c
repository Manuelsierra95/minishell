#include "cd.h"

void	*get_cd()
{
	t_cd		*cd;

	cd = malloc(sizeof(t_cd));
	cd->arg = g_shell->arg;
   	cd->fd = g_shell->fd[1];
	return (cd);
}
