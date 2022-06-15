/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:09:40 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:09:46 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	*get_export(void)
{
	t_export	*export;

	export = malloc(sizeof(t_export));
	export->arg = g_shell->arg;
	export->fd = g_shell->fd[1];
	return (export);
}
