/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:37:04 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 18:37:11 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	*get_echo(void)
{
	t_echo	*echo;

	echo = malloc(sizeof(t_echo));
	echo->arg = g_shell->arg;
	echo->fd = g_shell->fd[1];
	return (echo);
}
