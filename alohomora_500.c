/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expelliarmus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/01 19:15:34 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimal_push(t_stack *a, int pos_max, int nb_ra, int nb_rra)
{
	if (pos_max <= a->size / 2)
	{
		while (nb_ra)
		{
			rotate(a);
			nb_ra--;
		}
	}
	else
	{
		while (nb_rra)
		{
			reverse_rotate(a);
			nb_rra--;
		}
	}
}

int	sort_if_kinda_sorted(t_stack *a, t_stack *b)
{
	int	pos_max;
	int	nb_ra;
	int	nb_rra;

	pos_max = stack_sorted_at_this_pos(a);
	nb_ra = pos_max + 1;
	nb_rra = a->size - (pos_max + 1);
	if (pos_max < a->size - 5)
		return (NOT_OK);
	else
	{
		optimal_push(a, pos_max, nb_ra, nb_rra);
		while (a->size != pos_max + 1)
			push(a, b);
	}
	while (b->size)
		optimal_insertion_sort(b, a);
	while (a->head->index != 0)
		put_min_top(a);
	return (0);
}

int	sort_if_kinda_rev_sorted(t_stack *a, t_stack *b)
{
	int	pos_max;
	int	nb_ra;
	int	nb_rra;

	pos_max = stack_rev_sorted_at_this_pos(a);
	nb_ra = pos_max + 1;
	nb_rra = a->size - (pos_max + 1);
	if (pos_max < a->size - 5)
		return (NOT_OK);
	else
	{
		optimal_push(a, pos_max, nb_ra, nb_rra);
		while (a->size != pos_max + 1)
			push(a, b);
	}
	while (b->size)
		optimal_insertion_sort(b, a);
	while (a->head->index != 0)
		put_min_top(a);
	return (0);
}

static void	keep_in_a_push_in_b(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	while (size)
	{
		if (a->head->index > a->head->prev->index)
			rotate(a);
		else
			push(a, b);
		size--;
	}
}

void	sort_500_and_less(t_stack *a, t_stack *b)
{
	if (sort_if_kinda_sorted(a, b) == OK)
		return ;
	if (sort_if_kinda_rev_sorted(a, b) == OK)
		return ;
	if (a->size == 500)
	{
		while (a->size != 334)
			push_group(a, b, 0, 166);
		while (a->size != 168)
			push_group(a, b, 167, 332);
	}
	keep_in_a_push_in_b(a, b);
	while (b->size)
		optimal_insertion_sort(b, a);
	while (a->head->index != 0)
		put_min_top(a);
}
