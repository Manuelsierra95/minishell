/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:42:40 by msierra-          #+#    #+#             */
/*   Updated: 2021/09/18 17:01:17 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalpha_edit(int c)
{
	int	a;

	a = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') 
		|| c == '-' || (c >= '0' && c <= '9') || c == DOLLAR)
		a = 1;
	return (a);
}