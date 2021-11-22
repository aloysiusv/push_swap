/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:27:26 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/22 19:07:05 by lrandria         ###   ########.fr       */
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
}

void	rotate_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL || b->head == NULL)
		return ;
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->prev;
	stack->head->next = tmp;
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL || b->head == NULL)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
}
