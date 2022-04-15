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

int	count_pipes(char *input)
{
	int	i;
	int	num_pipes;

	i = 0;
	num_pipes = 0;
	while (input[i])
	{
		if (input[i] == PIPE)
			num_pipes++;
		i++;
	}
	return (num_pipes + (num_pipes + 1));
}

char	**u_split(char *input)
{
	char	**split_input;
	int		index;
	int		i;
	int		j;

	split_input = malloc(sizeof(char *) * (count_pipes(input) + 1));
	index = 0;
	i = 0;
	j = 0;
	if (count_pipes(input))
	{
		while (input[i])
		{
			if (input[i] == PIPE)
			{
				split_input[index++] = ft_substr(input, j, i - 1);
				split_input[index++] = ft_strdup("|");
				i++;
				j = i + 1;
			}
			i++;
		}
		split_input[index++] = ft_substr(input, j, i);
	}
	else
		split_input[index] = input;
	split_input[index++] = NULL;
	return (split_input);
}

char **split_input(char *input)
{
	char	**split_input;

	split_input = u_split(input);
	return (split_input);
}
