/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:58:13 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/19 18:59:43 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell()
{
	g_shell = (t_shell *)malloc(sizeof(t_shell));
	g_shell->exit = 0;
}

void	free_shell(void)
{
	if (g_shell)
	{
		free(g_shell);
		g_shell = NULL;
	}
}