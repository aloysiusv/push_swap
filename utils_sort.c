/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:04 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/30 02:19:25 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted_at_this_pos(t_stack *stack)
{
	size_t	size;
	int	pos;
	t_node	*iterator;
	t_node	*comparator;

	size = stack->size;
	pos = 0;
	iterator = stack->head;
	comparator = stack->head->next;
	while (size)
	{
		if (iterator->index > comparator->index)
		{
			printf("Sorted until pos %d\n", pos);
			return (pos);
		}
		iterator = iterator->next;
		comparator = comparator->next;
		pos++;
		size--;
	}
	printf("Sorted until pos %d\n", pos);
	return (pos);
}

size_t	find_min_pos(t_stack *stack)
{
	size_t	size;
	size_t	pos;
	size_t	i;
	t_node	*min;
	t_node	*comparator;

	size = stack->size;
	pos = 0;
	i = 0;
	if (size == 1)
		return (pos);
	else
	{
		min = stack->head;
		comparator = stack->head->next;
		while (size)
		{
			if (min->index > comparator->index)
			{
				min = comparator;
				pos = i + 1;
			}
			comparator = comparator->next;
			i++;
			size--;
		}
	}
	return (pos);
}

size_t	find_max_pos(t_stack *stack)
{
	size_t	size;
	size_t	pos;
	size_t	i;
	t_node	*max;
	t_node	*comparator;

	size = stack->size;
	pos = 0;
	i = 0;
	if (size == 1)
		return (pos);
	else
	{
		max = stack->head;
		comparator = stack->head->next;
		while (size)
		{
			if (max->index < comparator->index)
			{
				max = comparator;
				pos = i + 1;
			}
			comparator = comparator->next;
			i++;
			size--;
		}
	}
	return (pos);
}

void	put_min_top(t_stack *stack)
{
	size_t	size;
	size_t	min;

	size = stack->size;
	min = find_min_pos(stack);
	if (min == 0)
		return ;
	if (min == 1)
		swap(stack);
	if (min + 1 > size / 2)
		while (find_min_pos(stack) != 0)
			reverse_rotate(stack);
}
