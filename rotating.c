/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:27:26 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/01 02:27:26 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char c)
{
	t_node	*to_rotate;
	t_node	*to_save;

	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		to_rotate = stack->head;
		stack->head = stack->tail;
		stack->tail = to_rotate;
	}
	if (stack->size > 2)
	{
		to_rotate = stack->head;
		stack->head = stack->head->next;
		to_save = stack->tail;
		stack->tail = to_rotate;
		stack->head->prev = stack->tail;
		stack->tail->prev = to_save;
		stack->tail->next = stack->head;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack *stack, char c)
{
	t_node	*to_rotate;
	t_node	*to_save;

	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		to_rotate = stack->tail;
		stack->tail = stack->head;
		stack->head = to_rotate;
	}
	if (stack->size > 2)
	{
		to_rotate = stack->tail;
		stack->tail = stack->tail->prev;
		to_save = stack->head;
		stack->head = to_rotate;
		stack->tail->next = stack->head;
		stack->head->next = to_save;
		stack->head->prev = stack->tail;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}