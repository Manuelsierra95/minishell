/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:21:04 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 13:11:14 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_nbr(const char *s, char c)
{
	int	i;
	int	w_nbr;

	i = 0;
	w_nbr = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w_nbr++;
		i++;
	}
	return (w_nbr);
}

static int	get_word_len(const char *s, char c, int i)
{
	int	w_len;

	w_len = 0;
	while (s[i])
	{
		if (s[i] != c)
			w_len++;
		else
			break ;
		i++;
	}
	return (w_len);
}

static void	*free_mem(char **split, int i)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (NULL);
}

static char	**fill_split(const char *s, char c, int w_nbr, char **split)
{
	int	i;
	int	j;
	int	k;
	int	w_len;

	i = 0;
	j = 0;
	while (i < w_nbr)
	{
		while (s[j] == c)
			j++;
		w_len = get_word_len(s, c, j);
		split[i] = (char *) malloc((w_len + 1) * sizeof(char));
		if (!split[i])
			return (free_mem(split, i));
		k = 0;
		while (k < w_len)
			split[i][k++] = s[j++];
		split[i][k] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	int		w_nbr;
	char	**split;

	if (!s)
		return (NULL);
	w_nbr = get_word_nbr(s, c);
	split = (char **) malloc(sizeof (char *) * (w_nbr + 1));
	if (!split)
		return (NULL);
	return (fill_split(s, c, w_nbr, split));
}
