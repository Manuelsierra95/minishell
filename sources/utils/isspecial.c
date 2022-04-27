#include "../../includes/minishell.h"

int	d_isspecial(int c, int d)
{
	int	a;

	a = 0;
	if (c == PIPE)
		return (T_PIPE);
	else if (c == GREATER)
	{
		if (d == GREATER)
			return (T_GREATERGREATER);
		else
			return (T_GREATER);
	}
	else if (c == LESSER)
	{
		if (d == LESSER)
			return  (T_LESSERLESSER);
		else
			return (T_LESSER);
	}
	// Manejar error si no es nada de eso
	return (a);
}

int	s_isspecial(int c)
{
	int	a;

	a = 0;
	if (c == PIPE)
		return (T_PIPE);
	else if (c == GREATER)
		return (T_GREATER);
	else if (c == LESSER)
		return (T_LESSER);
	// Manejar error si no es nada de eso
	return (a);
}
