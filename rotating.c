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

void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = tmp;
	if (stack->name == 'a' && stack->rr <= 0)
		write(1, "ra\n", 4);
	if (stack->name == 'b' && stack->rr <= 0)
		write(1, "rb\n", 4);
	stack->count_op++;
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	a->count_op--;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->prev;
	stack->head->next = tmp;
	if (stack->name == 'a' && stack->rrr <= 0)
		write(1, "rra\n", 4);
	if (stack->name == 'b' && stack->rrr <= 0)
		write(1, "rrb\n", 4);
	stack->count_op++;
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	a->count_op--;
}
