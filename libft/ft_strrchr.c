/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:54:14 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:32 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	*str;
	char	ch;

	i = 0;
	ch = (char) c;
	str = (char *) s;
	res = NULL;
	while (str[i])
	{
		if (str[i] == ch)
			res = &str[i];
		i++;
	}
	if (str[i] == ch)
		res = &str[i];
	return (res);
}
