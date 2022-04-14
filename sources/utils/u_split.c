/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:21:04 by mbarylak          #+#    #+#             */
/*   Updated: 2021/09/23 13:00:26 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_word_nbr(const char *s, char c, int n_quotes)
{
	int	i;
	int	w_nbr;

	i = 0;
	w_nbr = 0;
	while (s[i])
	{
		if (s[i] == D_QUOTE)
		{
			i++;
			while (s[i] && n_quotes != 0)
			{
				if (s[i] == D_QUOTE)
					n_quotes--;
				i++;
			}
			i++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w_nbr++;
		i++;
	}
	return (w_nbr);
}

static int	get_word_len(const char *s, char c, int i, int n_quotes)
{
	int	w_len;

	w_len = 0;
	while (s[i])
	{
		if (s[i] == D_QUOTE)
		{
			while (s[++i] && n_quotes != 0)
			{
				if (s[i] == D_QUOTE)
					n_quotes--;
				w_len++;
			}
			i++;
			w_len += 2;
			break ;
		}
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

static char	**fill_split(const char *s, char c, int w_nbr[2], char **split)
{
	int	i;
	int	j;
	int	k;
	int	w_len;

	i = 0;
	j = 0;
	while (i < w_nbr[0])
	{
		while (s[j] == c)
			j++;
		w_len = get_word_len(s, c, j, w_nbr[1]);
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

char	**u_split(const char *s, char c, int n_quotes)
{
	int		w_nbr[2];
	char	**split;

	if (!s)
		return (NULL);
	w_nbr[1] = n_quotes;
	w_nbr[0] = get_word_nbr(s, c, n_quotes);
	split = (char **) malloc(sizeof (char *) * (w_nbr[0] + 1));
	if (!split)
		return (NULL);
	return (fill_split(s, c, w_nbr, split));
}
