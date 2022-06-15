/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:03:41 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:03:55 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"
#include "minishell.h"

void	*get_pwd(void)
{
	t_pwd	*pwd;

	pwd = malloc(sizeof(t_pwd));
	pwd->fd = g_shell->fd[1];
	return (pwd);
}
