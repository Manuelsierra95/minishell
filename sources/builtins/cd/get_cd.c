/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:38:00 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 18:38:45 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	*get_cd(void)
{
	t_cd	*cd;

	cd = malloc(sizeof(t_cd));
	cd->arg = g_shell->arg;
	cd->fd = g_shell->fd[1];
	return (cd);
}
