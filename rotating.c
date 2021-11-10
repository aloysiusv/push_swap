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

void	rotate(t_stack *stack, char name)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = tmp;
	if (name == 'a')
		write(1, "ra\n", 4);
	if (name == 'b')
		write(1, "rb\n", 4);
	stack->count_op++;
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
	a->count_op--;
}

void	reverse_rotate(t_stack *stack, char name)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->prev;
	stack->head->next = tmp;
	if (name == 'a')
		write(1, "rra\n", 4);
	if (name == 'b')
		write(1, "rrb\n", 4);
	stack->count_op++;
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
	a->count_op--;
}
