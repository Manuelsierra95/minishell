/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:37:41 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 18:37:46 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "libft.h"
# include "minishell.h"

typedef struct s_cd
{
	char	**arg;
	int		fd;
}	t_cd;

void	*get_cd(void);
void	*ft_cd(void *b_struct);

#endif
