/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:04 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/16 19:18:59 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_sorted_at_this_pos(t_stack *stack)
{
	int		pos;
	int		size;
	t_node	*iterator;
	t_node	*comparator;

	pos = 0;
	size = stack->size;
	iterator = stack->head;
	comparator = stack->head->next;
	while (--size)
	{
		if (iterator->index > comparator->index)
			return (pos);
		pos++;
		iterator = iterator->next;
		comparator = comparator->next;
	}
	return (pos);
}

int		stack_rev_sorted_at_this_pos(t_stack *stack)
{
	int		pos;
	int		size;
	t_node	*iterator;
	t_node	*comparator;

	pos = 0;
	size = stack->size;
	iterator = stack->head;
	comparator = stack->head->next;
	while (--size)
	{
		if (iterator->index < comparator->index)
			return (pos);
		pos++;
		iterator = iterator->next;
		comparator = comparator->next;
	}
	return (pos);
}

int		find_pos(t_stack *stack, int index)
{
	t_node	*iterator;
	int		pos;

	iterator = stack->head;
	pos = 0;
	while (iterator->index != index)
	{
		iterator = iterator->next;
		pos++;
	}
	return (pos);
}
