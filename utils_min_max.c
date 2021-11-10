/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:25:52 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/10 17:28:12 by lrandria         ###   ########.fr       */
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
