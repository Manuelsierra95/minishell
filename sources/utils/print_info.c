/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:33:27 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/01 19:36:37 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		dprintf(2, "%s", env[i]);
		i++;
	}
}

void	print_list(t_list *env)
{
	t_list	*aux;

	aux = env;
	while (aux)
	{
		if (aux->content)
			dprintf(2, "%s\n", aux->content);
		aux = aux->next;
	}
}
