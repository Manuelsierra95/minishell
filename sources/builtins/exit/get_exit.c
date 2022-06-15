/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:07:49 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:07:55 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	*get_exit(void)
{
	t_exit	*exit;

	exit = malloc(sizeof(t_exit));
	exit->arg = g_shell->arg;
	return (exit);
}
