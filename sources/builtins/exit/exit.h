/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:08:09 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:08:20 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "libft.h"
# include "minishell.h"

typedef struct s_exit
{
	char	**arg;
}	t_exit;

void	*get_exit(void);
void	*ft_exit(void *b_struct);

#endif
