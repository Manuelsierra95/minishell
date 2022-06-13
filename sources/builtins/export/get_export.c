#include "export.h"

void	*get_export()
{
	t_export	*export;

	export = malloc(sizeof(t_export));
	export->arg = g_shell->arg;
	export->fd = g_shell->fd[1];
	return (export);
}
