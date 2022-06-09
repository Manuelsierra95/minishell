#include "cd.h"

void	*get_cd()
{
	t_cd		*cd;

	cd = malloc(sizeof(t_cd));
	cd->arg = g_shell->arg; //Es el cmd que devuelve el arbol ¿por que g_shell->arg y no tree->cmd? 
	return (cd);
}
