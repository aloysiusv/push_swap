/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:53:39 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:53:39 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicates(long *tab, size_t nb_of_elements)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < nb_of_elements - 1)
	{
		j = i + 1;
		while (j < nb_of_elements)
		{
			if (tab[i] == tab[j])
				return (NOT_OK);
			j++;
		}
		i++;
	}
	return (OK);
}

int	stock_and_seek_duplicates(size_t nb_of_elements, char **argv)
{
	size_t	i;
	long	tab[nb_of_elements];

	i = 0;
	while (i < nb_of_elements)
	{
		tab[i] = ft_atol(argv[i]);
		if (tab[i] < INT_MIN || tab[i] > INT_MAX)
		{
			// printf("Not an int.\n");
			return (NOT_OK);
		}
		i++;
	}
	if (is_duplicates(tab, nb_of_elements) == NOT_OK)
	{
		// printf("Duplicates.\n");
		return (NOT_OK);
	}
	return (OK);
}

int	is_str_int_sized(char *str)
{
	if (str[0] == '-')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 10)
		return (NOT_OK);
	return (OK);
}

int	is_str_only_digits(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			;
		else if (ft_is_digit(str[i]) == 0)
			return (NOT_OK);
		i++;
	}
	return (OK);
}

int	is_input_valid(size_t nb_of_elements, char **input)
{
	size_t	i;
	
	// if (nb_of_elements < 2)
	// {
	// 	// printf("Not enough args.");
	// 	return (NOT_OK);
	// }
	i = 0;
	while (input[i])
	{
		if (is_str_only_digits(input[i]) == NOT_OK)
		{
			// printf("Non-digits.\n");
			return (NOT_OK);
		}
		if (is_str_int_sized(input[i]) == NOT_OK)
		{
			// printf("Bigger than int size\n");
			return (NOT_OK);
		}
		i++;
	}
	if (stock_and_seek_duplicates(nb_of_elements, input) == NOT_OK)
		return(NOT_OK);
	// printf("It's valid.\n");
	return (OK);
}
