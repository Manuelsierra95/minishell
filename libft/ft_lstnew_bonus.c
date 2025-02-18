/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:54:45 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:16:52 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	struct s_list	*list;

	list = malloc(sizeof (content));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
