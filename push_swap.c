/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:24:44 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/28 21:26:49 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	
}

int	is_array_sorted(t_stack a)
{
	
}

void	init_stacks(t_stack *a, t_stack *b, char **argv)
{
	a->size =  
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
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_input_valid(int argc, char **argv)
{
	size_t	i;
	
	if (argc < 3)
		return (FALSE);
	else
	{
		i = 0;
		while (argv[i])
		{
			if (is_str_only_digits(argv[i]) == FALSE)
				return (FALSE);
			i++;
		}
		if (is_not_duplicates(argv) == FALSE)
			return (FALSE);
		return (TRUE);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (is_input_valid(argc, argv) == TRUE)
	{
		init_stacks(&a, &b, argv);
		if (is_array_sorted(a) == TRUE)
			return (0);
		else
			push_swap(&a, &b);
	}
	else
		return (1);
	return (0);
}
