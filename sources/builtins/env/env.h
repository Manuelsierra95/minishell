/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:06:23 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:07:03 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include "minishell.h"

typedef struct s_env
{
	t_list	*env;
	int		fd;
}	t_env;

void	*ft_env(void *b_struct);
void	*get_env(void);

#endif
