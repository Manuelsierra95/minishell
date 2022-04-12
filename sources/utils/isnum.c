#include "minishell.h"

int	ft_isnum(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
			return (0);
		i++;
	}
	return (1);
}
