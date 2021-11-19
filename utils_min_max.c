/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:25:52 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/18 20:40:59 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*min;
	t_node	*comparator;
    int      size;

	if (stack->head == NULL)
		return (NULL);
	size = stack->size;
	min = stack->head;
    if (size == 1)
		return (min);
	else
	{
		comparator = stack->head->next;
		while (size)
		{
			if (min->index > comparator->index)
				min = comparator;
			comparator = comparator->next;
			size--;
		}
	}
	return (min);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*max;
	t_node	*comparator;
    int     size;

	size = stack->size;
    if (stack->head == NULL)
		return (NULL);
	max = stack->head;
	if (size == 1)
		return (max);
	else
	{
		comparator = stack->head->next;
		while (size)
		{
			if (max->index < comparator->index)
				max = comparator;
			comparator = comparator->next;
			size--;
		}
	}
	return (max);
}

void	put_min_top(t_stack *stack)
{
	int		size;
	int		min_pos;
	t_node	*min;

	size = stack->size;
	if (!size)
		return ;
	min = find_min(stack);
	min_pos = find_pos(stack, min->index);
	if (min_pos == 0)
		return ;
	while (stack->head->index != min->index)
	{
		if (min_pos <= size / 2) // min_pos + 1;
			rotate(stack);
		if (min_pos > size / 2) // min_pos + 1;
			reverse_rotate(stack);
	}
}

void	put_max_top(t_stack *stack)
{
	int		size;
	int		max_pos;
	t_node	*max;

	size = stack->size;
	if (!size)
		return ;
	max = find_max(stack);
	max_pos = find_pos(stack, max->index);
	if (max_pos == 0)
		return ;
	while (stack->head->index != max->index)
	{
		if (max_pos <= size / 2) // max_pos + 1;
			rotate(stack);
		if (max_pos > size / 2) // max_pos + 1;
			reverse_rotate(stack);
	}
}
