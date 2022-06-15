/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:04:10 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:04:56 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PWD_H
# define PWD_H

# include "libft.h"

typedef struct s_pwd
{
	int	fd;
}	t_pwd;

void	*ft_pwd(void *b_struct);
void	*get_pwd(void);

#endif
