/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping_pushing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:53:29 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:53:29 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c)
{
	t_node	*tmp;

	if (stack->size > 2)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		stack->head->next = tmp;
		if (c == 'a')
			write(1, "sa\n", 3);
		if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	swap_both(t_stack *stack, t_stack *other_stack)
{
	swap(stack);
	swap(other_stack);
	write(1, "ss\n", 3);
}

void	push(t_stack *receiving, t_stack *pushing, char pushed_on)
{
	t_node	*tmp;

	if (pushing != NULL)
	{
	tmp = add_top_node(receiving->head, pushing->head->num);
	if (pushing->size > 1)
		pushing->head->next = pushing->head;
	delete(pushing->head);
	pushing->size = pushing->size - 1;
	receiving->size = receiving->size + 1;
	if (pushed_on == 'a')
		write(1, "pa\n", 3);
	if (pushed_on == 'b')
		write(1, "pb\n", 3);
	}
}
