/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:25 by msierra-          #+#    #+#             */
/*   Updated: 2025/02/18 11:23:28 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

static int	ft_ismax(int sign, unsigned long long nbr)
{
	if (sign == 1 && nbr > LLONG_MAX)
		return (-1);
	if (sign == -1 && nbr > LLONG_MAX)
		return (0);
	return (nbr * sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	return (ft_ismax(sign, nbr));
}
