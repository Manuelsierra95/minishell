/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:11:49 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:11:54 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

void	*get_unset(void)
{
	t_unset	*unset;

	unset = malloc(sizeof(t_unset));
	unset->arg = g_shell->arg;
	return (unset);
}
