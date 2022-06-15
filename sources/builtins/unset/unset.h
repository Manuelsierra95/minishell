/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:12:03 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:12:33 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "libft.h"
# include "minishell.h"

typedef struct s_unset
{
	char	**arg;
}	t_unset;

void	*get_unset(void);
void	*ft_unset(void *b_struct);

#endif
