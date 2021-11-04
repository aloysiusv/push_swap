/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:38:27 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:38:27 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
		if (a->size <= 5)
			sort_5_and_less(a, b);
		if (a->size > 5 && a->size <= 100)
			sort_100_and_less(a, b);
// 		if a->size <= 500)
// 			sort_500_and_less(a, b);
// 		if (a->size > 500)
// 			printf("Let's radix lol.");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (is_input_valid(argc - 1, argv + 1) == OK)
	{
		a = (t_stack *)malloc(sizeof(t_stack));
		b = (t_stack *)malloc(sizeof(t_stack));
		if (a == NULL || b == NULL)
			return (0);
		init_stacks(a, b, argc - 1, argv + 1);
		if (is_stack_sorted(a) == OK)
		{
			write(1, "Stack is already sorted.\n", 25);
			delete_stack(a);
			delete_stack(b);
			return (0);
		}
		else
			push_swap(a, b);
		printf("COUNT = %zu\n", a->count_op + b->count_op);
		delete_stack(a);
		delete_stack(b);
	}
	else
	{
		write(1, "Error\n", 7);
		return (0);
	}
	return (0);
}
