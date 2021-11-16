/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:25:52 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/16 14:53:42 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     find_min(t_stack *stack)
{
	t_node	*min;
	t_node	*comparator;
    int      size;

	if (stack->head == NULL)
		return (-1);
	size = stack->size;
    if (size == 1)
		return (stack->head->index);
	else
	{
		min = stack->head;
		comparator = stack->head->next;
		while (size)
		{
			if (min->index > comparator->index)
				min = comparator;
			comparator = comparator->next;
			size--;
		}
	}
	return (min->index);
}

int     find_max(t_stack *stack)
{
	t_node	*max;
	t_node	*comparator;
    int     size;

	size = stack->size;
    if (stack->head == NULL)
        return (-1);
	else if (size == 1)
		return (stack->head->index);
	else
	{
		max = stack->head;
		comparator = stack->head->next;
		while (size)
		{
			if (max->index < comparator->index)
				max = comparator;
			comparator = comparator->next;
			size--;
		}
	}
	return (max->index);
}

void	put_min_top(t_stack *stack)
{
	int	size;
	int	min_pos;
	int	min;

	size = stack->size;
	if (!size)
		return ;
	min = find_min(stack);
	min_pos = find_pos(stack, min);
	// printf("Min_pos = %d\n", min_pos);
	if (min_pos == 0)
		return ;
	while (stack->head->index != min)
	{
		if (min_pos <= size / 2) // min_pos + 1;
			rotate(stack);
		if (min_pos > size / 2) // min_pos + 1;
			reverse_rotate(stack);
	}
}

void	put_max_top(t_stack *stack)
{
	int	max;
	int	size;

	size = stack->size;
	if (!size)
		return ;
	max = find_pos(stack, find_max(stack));
	if (max == 0)
		return ;
	while (stack->head->index != 0)
	{
		if (max + 1 >= size / 2)
			reverse_rotate(stack);
		if (max + 1 < size / 2)
			rotate(stack);
	}
}
