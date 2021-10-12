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
	t_node	tmp[1];

	if (stack->size >= 2)
	{
		tmp->num = stack->head->num;
		stack->head->num = stack->head->next->num;
		stack->head->next->num = tmp->num;
		if (c == 'a')
			write(1, "sa\n", 3);
		if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}

void	push(t_stack *receiving, t_stack *pushing, char pushed_on)
{
	t_node	*to_push;
	t_node	*to_save;
	
	if (pushing->head != NULL)
	{
		to_push = pushing->head;
		pushing->head = pushing->head->next;
		to_save = receiving->head;
		receiving->head = to_push;
		if (receiving->head != NULL)
			receiving->head->next = to_save;
		if (receiving->size >= 2)
			receiving->head->prev = receiving->tail;
		printf("Node [%d] has been pushed.\n", receiving->head->num);
		pushing->size--;
		receiving->size++;
		if (pushed_on == 'a')
			write(1, "pa\n", 3);
		if (pushed_on == 'b')
			write(1, "pb\n", 3);
	}
}
