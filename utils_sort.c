/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:04 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/29 18:52:44 by lrandria         ###   ########.fr       */
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
	t_node	*smallest;
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
		smallest = stack->head;
		comparator = stack->head->next;
		while (size)
		{
			if (smallest->index > comparator->index)
			{
				smallest = comparator;
				pos = i + 1;
			}
			comparator = comparator->next;
			i++;
			size--;
		}
	}
	// printf("Min =  %zu\n", pos);
	return (pos);
}

size_t	find_max_pos(t_stack *stack)
{
	size_t	size;
	size_t	pos;
	size_t	i;
	t_node	*biggest;
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
		biggest = stack->head;
		comparator = stack->head->next;
		while (size)
		{
			if (biggest->index < comparator->index)
			{
				biggest = comparator;
				pos = i + 1;
			}
			comparator = comparator->next;
			i++;
			size--;
		}
	}
	printf("Max =  %zu\n", pos);
	return (pos);
}

void	put_min_top(t_stack *stack)
{
	size_t	size;
	size_t	pos;

	size = stack->size;
	pos = find_min_pos(stack);
	if (pos == 0)
		return ;
	if (pos == 1)
		swap(stack);
	if (pos > size / 2)
		while (find_min_pos(stack) != 0)
			reverse_rotate(stack);
}

// int	find_pos_biggest(t_stack *stack)
// {
// 	t_node	*max;
// 	t_node	*comparator;

// 	if (stack->head == NULL)
// 		return ;
// 	if (stack->size == 1)
// 		return (max = stack->head->pos);
// 	else
// 	{	
// 		max = stack->head;
// 		comparator = stack->head->next;
// 		while(stack->size)
// 		{
// 			if (max->value > comparator->value && comparator->index == -1)
// 			{
// 				max = comparator;
// 				comparator = comparator->next;
// 			}
// 			stack->size--;
// 		}
// 	}
// 	return (max->pos);
// }

