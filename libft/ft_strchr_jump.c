/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_jump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:17:04 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:11:26 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include<stdio.h>

char	*ft_strchr_jump(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	i = 0;
	ch = (char) c;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == ch)
			return (&str[++i]);
		i++;
	}
	if (str[i] == ch)
		return (&str[i]);
	return (NULL);
}
