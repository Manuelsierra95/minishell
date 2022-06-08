#include "cd.h"

void	*get_cd()
{
	t_cd		*cd;

	cd = malloc(sizeof(t_cd));
	cd->arg = g_shell->arg; //Es el comando que devuelve el arbol
	cd->env = g_shell->env; 
	return (cd);
}
