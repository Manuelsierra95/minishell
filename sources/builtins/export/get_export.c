#include "export.h"

void	*get_export()
{
	t_export	*export;

	export = malloc(sizeof(t_export));
	export->arg = g_shell->arg; // por que lo sacas de shell y no de tree??
	export->fd = g_shell->fd[1];
	return (export);
}
