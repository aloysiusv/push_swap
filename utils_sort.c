/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:04 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/16 19:18:59 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_stack_sorted(t_stack *stack)
{
	int		size;
	t_node	*iterator;
	t_node	*comparator;

	size = stack->size;
	iterator = stack->head;
	comparator = stack->head->next;
	while (size)
	{
		if (iterator->index > comparator->index)
			return (NOT_OK);
		iterator = iterator->next;
		comparator = comparator->next;
		size--;
	}
	return (OK);
}

int		find_pos(t_stack *stack, int index)
{
	t_node	*iterator;
	int		i;

	iterator = stack->head;
	i = 0;
	while (iterator->index != index)
	{
		iterator = iterator->next;
		i++;
	}
	return (i);
}

