/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/01 19:15:34 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node  *find_senpai(t_stack *stack, int current_index)
{
    t_node  *iterator;
	t_node	*senpai;
	int		size;

	iterator = stack->head;
	senpai = stack->head;
	size = stack->size;
    while (size)
    {
		if (iterator->prev->index < current_index && iterator->index > current_index)
		{
			senpai = iterator;
			break ;
		}
		iterator = iterator->next;
		size--;
	}
    return (senpai);
}

static int	calculate_steps_to_top(t_stack *stack, int index)
{
	int	index_pos;
	int	res;

	index_pos = find_pos(stack, index);
	if (index_pos <= stack->size / 2)
		res = index_pos;
	else
		res = stack->size - index_pos;
	return (res);
}

static int	calculate_moves(t_stack *a, t_stack *b, int current_index)
{
	t_node	*senpai;
	int	index_moves;
	int	senpai_moves;
	int	moves;

	if (a->head == NULL || b->head == NULL)
		return (0);
	senpai = find_senpai(a, current_index);
	senpai_moves = calculate_steps_to_top(a, senpai->index);
	index_moves = calculate_steps_to_top(b, current_index);
	moves = senpai_moves + index_moves + 1;
	return (moves);
}

static t_node	*find_cheapest_node(t_stack *a, t_stack *b)
{
	t_node	*best_node;
	t_node	*comparator;
	int		size;

	best_node = b->head;
	comparator = b->head->next;
	best_node->moves = calculate_moves(a, b, best_node->index);
	size = b->size;
	while (size - 1)
	{
		comparator->moves = calculate_moves(a, b, comparator->index);
		if (comparator->moves < best_node->moves)
			best_node = comparator;
		comparator = comparator->next;
		size--;
	}
	return (best_node);
}

void    optimal_insertion_sort(t_stack *b, t_stack *a)
{
	t_node	*best_node;
	t_node	*senpai;

    if (a->head == NULL || b->head == NULL)
	{
		if (a->head == NULL)
			push(b, a);
		return ;
	}
	best_node = find_cheapest_node(a, b);
	if (is_new_min_max(a, b, best_node->index) == 1)
		return ;
	senpai = find_senpai(a, best_node->index);
	stock_rotation_flags(a, senpai->index);
	stock_rotation_flags(b, best_node->index);
	do_all_rot_equal(a, b);
	do_rot_inferior(a, b);
	do_rot_superior(a, b);
	do_rev_rot_inferior(a, b);
	do_rev_rot_superior(a, b);
	push(b, a);
}