/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:04 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/10 19:40:07 by lrandria         ###   ########.fr       */
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

void	put_min_top(t_stack *stack, char name)
{
	int	size;
	int	min;

	size = stack->size;
	if (!size)
		return ;
	min = find_min_pos(stack);
	if (min == 0)
		return ;
	if (min == 1)
		swap(stack, name);
	while (find_min_pos(stack) != 0)
	{
		if (min + 1 > size / 2)
			reverse_rotate(stack, name);
		if (min + 1 <= size / 2)
			rotate(stack, name);
	}
}

void	put_max_top(t_stack *stack, char name)
{
	int	max;

	if (!stack->size)
		return ;
	max = find_max_pos(stack);
	if (max == 0)
		return ;
	if (max == 1)
		swap(stack, name);
	while (find_max_pos(stack) != 0)
	{
		if (max + 1 > stack->size / 2)
			reverse_rotate(stack, name);
		if (max + 1 <= stack->size / 2)
			rotate(stack, name);
	}
}
