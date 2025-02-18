/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:02:31 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:14:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (src[i] && (dst_len + i) < dstsize - 1 && dstsize != 0)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (i != 0)
		dst[dst_len + i] = '\0';
	if (dstsize < dst_len)
		count = dstsize + src_len;
	else
		count = dst_len + src_len;
	return (count);
}
