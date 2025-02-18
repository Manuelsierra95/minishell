/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:44:01 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:41 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, int start, int len)
{
	char	*a;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (int) ft_strlen(s))
		len = 0;
	if (len > (int) ft_strlen(s))
		len = (int) ft_strlen(s);
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i + start < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
