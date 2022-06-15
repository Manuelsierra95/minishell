/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:06:09 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:06:15 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	*get_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->env = g_shell->env;
	env->fd = g_shell->fd[1];
	return (env);
}
