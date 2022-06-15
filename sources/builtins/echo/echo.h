/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:35:34 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 18:35:50 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include "libft.h"
# include "minishell.h"

typedef struct s_echo
{
	int		fd;
	char	**arg;
}	t_echo;

void	*ft_echo(void *b_struct);
void	*get_echo(void);

#endif
