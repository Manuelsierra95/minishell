#include "export.h"

void	*get_export()
{
	t_export	*export;

	export = malloc(sizeof(t_export));
	export->arg = g_shell->arg;
	export->env = g_shell->env;
	export->fd = g_shell->fd;
	export->secret = g_shell->secret;
	return (export);
}
