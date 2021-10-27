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
	(void)b;
	init_index(a);
	if (a->size <= 5)
		sort_5_and_less(a, b);
// 	if (a->stack_size <= 100)
// 		sort_100_and_less(a, b);
// 	if a->stack_size <= 500)
// 		sort_500_and_less(a, b);
// 	if (a->stack_size > 500)
// 		printf("Let's radix lol.");
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
		{
			write(1, "Let's do push_swap!\n", 21);
			// swap(a, 'a');
			// push(a, b, 'b');
			// push(a, b, 'b');
			// push(a, b, 'b');
			// push(a, b, 'b');
			// push(b, a, 'a');
			// reverse_rotate(a, 'a');
			// rotate(b, 'b'); 
			push_swap(a, b);
		}
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
