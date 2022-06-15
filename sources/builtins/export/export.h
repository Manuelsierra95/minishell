/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:09:11 by mbarylak          #+#    #+#             */
/*   Updated: 2022/06/15 21:09:29 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "libft.h"
# include "minishell.h"

typedef struct s_export
{
	char	**arg;
	t_list	*env;
	t_list	*secret;
	int		fd;
}	t_export;

void	*ft_export(void *b_struct);
void	*get_export(void);

#endif
