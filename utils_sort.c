/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:04 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/03 03:18:42 by lrandria         ###   ########.fr       */
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

int		find_min_pos(t_stack *stack)
{
	int	size;
	int	pos;
	int	i;
	t_node	*min;
	t_node	*comparator;

	if (stack->head == NULL)
		return (-1);
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

int		find_max_pos(t_stack *stack)
{
	int	size;
	int	pos;
	int	i;
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
	int	size;
	int	min;

	size = stack->size;
	if (!size)
		return ;
	min = find_min_pos(stack);
	if (min == 0)
		return ;
	if (min == 1)
		swap(stack);
	while (find_min_pos(stack) != 0)
	{
		if (min + 1 > size / 2)
			reverse_rotate(stack);
		if (min + 1 <= size / 2)
			rotate(stack);
	}
}

void	put_max_top(t_stack *stack)
{
	int	max;

	if (!stack->size)
		return ;
	max = find_max_pos(stack);
	if (max == 0)
		return ;
	if (max == 1)
		swap(stack);
	while (find_max_pos(stack) != 0)
	{
		if (max + 1 > stack->size / 2)
			reverse_rotate(stack);
		if (max + 1 <= stack->size / 2)
			rotate(stack);
	}
}

