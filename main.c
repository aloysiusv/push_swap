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

// void	push_swap(t_stack *stack_a)
// {
// 	t_stack	*stack_b;
//
// 	stack_b = (t_stack *)malloc(sizeof(t_stack));
// 	if (stack_b == NULL)
// 		return (NULL);
// 	if (stack_a->stack_size <= 5)
// 		sort_5_or_less(stack_a, stack_b);
// 	if (stack_a->stack_size <= 100)
// 		sort_100_and_less(stack_a, stack_b);
// 	if stack_a->stack_size <= 500)
// 		sort_500_and_less(stack_a, stack_b);
// 	if (stack_a->stack_size > 500)
// 		printf("Sorry, too lazy for that...");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (0);
	if (is_input_valid(argc - 1, argv + 1) == OK)
	{
		fill_stack(stack_a, argc - 1, argv + 1);
		if (is_stack_sorted(stack_a) == OK)
		{
			write(1, "Stack is already sorted\n", 25);
			delete_stack(stack_a);
			return (0);
		}
		else
		{
			write(1, "Let's do push_swap!\n", 21);
			//push_swap(stack_a);
		}
	}
	else
	{
		write(1, "Error\n", 7);
		return (0);
	}
	delete_stack(stack_a);
	return (0);
}
