/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:41:24 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:41:24 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *num_ascii)
{
	size_t	i;
	short	sign;
	int		res;

	i = 0;
	while ((num_ascii[i] >= 9 && num_ascii[i] <= 13) || num_ascii[i] == 32)
		i++;
	sign = 1;
	if (num_ascii[i] == '-')
	{
		sign *= -1;
		i++;
	}
	res = 0;
	while (num_ascii[i] >= '0' && num_ascii[i] <= '9')
	{
		res = (res * 10) + (num_ascii[i] - '0') * sign;
		i++;
	}
	return (res);
}

long	ft_atol(const char *num_ascii)
{
	size_t	i;
	short	sign;
	long	res;

	i = 0;
	while ((num_ascii[i] >= 9 && num_ascii[i] <= 13) || num_ascii[i] == 32)
		i++;
	sign = 1;
	if (num_ascii[i] == '-')
	{
		sign *= -1;
		i++;
	}
	res = 0;
	while (num_ascii[i] >= '0' && num_ascii[i] <= '9')
	{
		res = (res * 10) + (num_ascii[i] - '0') * sign;
		i++;
	}
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
