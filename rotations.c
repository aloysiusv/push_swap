/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
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

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = tmp;
	if (stack->name == 'a' && stack->rr <= 0)
		write(1, "ra\n", 3);
	if (stack->name == 'b' && stack->rr <= 0)
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL || b->head == NULL)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->prev;
	stack->head->next = tmp;
	if (stack->name == 'a' && stack->rrr <= 0)
		write(1, "rra\n", 4);
	if (stack->name == 'b' && stack->rrr <= 0)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL || b->head == NULL)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
