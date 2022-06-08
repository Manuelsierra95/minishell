#include "unset.h"

void	*get_unset()
{
	t_unset	*unset;

	unset = malloc(sizeof(t_unset));
	unset->arg = g_shell->arg;
	return (unset);
}
