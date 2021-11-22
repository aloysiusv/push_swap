/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups_and_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/22 18:58:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stock_rotation_flags(t_stack *stack, int index)
{
	t_node	*iterator;
	int		best_pos;

	iterator = stack->head;
	best_pos = find_pos(stack, index);
	if (best_pos <= stack->size / 2)
	{
		while (iterator->index != index)
		{
			stack->rotate++;
			iterator = iterator->next;
		}
	}
	else
	{
		while (iterator->index != index)
		{
			stack->reverse_rotate++;
			iterator = iterator->prev;
		}
	}
}

static int	choose_best_in_group(t_node **first, t_node **last,
	int idx_min, int idx_max)
{
	int	pos_first;
	int	pos_last;
	int	i;

	i = 0;
	while (i < idx_max)
	{
		if ((*first)->index >= idx_min && (*first)->index < idx_max)
			break ;
		*first = (*first)->next;
		i++;
	}
	pos_first = i;
	i = 0;
	while (i < idx_max)
	{
		if ((*last)->index >= idx_min && (*last)->index < idx_max)
			break ;
		*last = (*last)->prev;
		i++;
	}
	pos_last = i;
	if (pos_first <= pos_last)
		return (0);
	return (1);
}

void	push_group(t_stack *a, t_stack *b, int idx_min, int idx_max)
{
	t_node	*first;
	t_node	*last;
	int		best;

	if (!a->head)
		return ;
	first = a->head;
	last = a->head->prev;
	best = choose_best_in_group(&first, &last, idx_min, idx_max);
	if (best == 0)
	{
		while (a->head->index != first->index)
			rotate(a);
	}
	else
	{
		while (a->head->index != last->index)
			reverse_rotate(a);
	}
	push(a, b);
}
