/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:41:25 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:15:37 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	int		start;
	int		end;
	char	*strim;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && char_in_set(s[start], set))
		start++;
	end = ft_strlen(s);
	while (end > start && char_in_set(s[end - 1], set))
		end--;
	strim = (char *) ft_calloc(end - start + 1, sizeof(char));
	if (!strim)
		return (NULL);
	while (end > start)
	{
		end--;
		strim[end - start] = s[end];
	}
	return (strim);
}
