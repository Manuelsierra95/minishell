/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspecial.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:05:58 by mbarylak          #+#    #+#             */
/*   Updated: 2022/04/18 16:06:49 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspecial(int c, int d)
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
			return (T_LESSERLESSER);
		else
			return (T_LESSER);
	}
	// Manejar error si no es nada de eso
	return (a);
}
