/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/15 03:43:01 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int choose_r_rr_groups(t_node **first, t_node **last, int group)
{
    int pos_first;
    int pos_last;
    int i;

    i = 0;
    while (i < group)
    {
        if ((*first)->index >= 0 && (*first)->index < group)
            break ;
        *first = (*first)->next;
        i++;
    }
    pos_first = i;
    i = 0;
    while (i < group)
    {
        if ((*last)->index >= 0 && (*last)->index < group)
            break ;
        *last = (*last)->prev;
        i++;
    }
    pos_last = i;
    if (pos_first <= pos_last)
        return (0);
    return (1);
}

static void	push_first_group(t_stack *a, t_stack *b, int group)
{
    t_node  *first;
    t_node  *last;
    int     best;

    if (!a->head)
        return ;
    first = a->head;
    last = a->head->prev;
    best = choose_r_rr_groups(&first, &last, group);
    if (best == 0)
        while (a->head->index != first->index)
            rotate(a, 'a');
    else
        while (a->head->index != last->index)
            reverse_rotate(a, 'a');
    push(a, b, 'b');
}

static void tame_chaos(t_stack *a, t_stack *b)
{
    int	mid;

	if (a->size < 100)
	{
		mid = a->size / 2;
		while (a->size != mid)    
        	push_first_group(a, b, mid);
    	while (a->size != 2)
			push(a, b, 'b');
		sort_2(a);
		while (a->size)
		{
			put_min_top(a, 'a');
			push(a, b, 'b');
		}
	}
 	if (a->size == 100)
	{
		while (a->size != 80)    
        	push_first_group(a, b, 19);
    	while (a->size != 60)
        	push_first_group(a, b, 39);
    	while (a->size != 40)
        	push_first_group(a, b, 59);
    	while (a->size != 20)
        	push_first_group(a, b, 79);
   		while (a->size)
    	{
			push_first_group(a, b, 99);
		}
		// while (b->size)
		// {
		// 	put_max_top(b, 'b');
		// 	push(b, a, 'a');
		// }
		// return ;
	}
	if (a->size == 500)
	{
		while (a->size != 455)    
        	push_first_group(a, b, 44);
    	while (a->size != 410)
        	push_first_group(a, b, 89);
    	while (a->size != 365)
        	push_first_group(a, b, 134);
    	while (a->size != 320)
        	push_first_group(a, b, 179);
		while (a->size != 275)
        	push_first_group(a, b, 224);
		while (a->size != 230)
        	push_first_group(a, b, 269);
		while (a->size != 185)
        	push_first_group(a, b, 314);
		while (a->size != 140)
        	push_first_group(a, b, 359);
		while (a->size != 95)
        	push_first_group(a, b, 404);
		while (a->size != 50)
        	push_first_group(a, b, 449);
   		while (a->size)
    	{
			push_first_group(a, b, 499);
		}
		// while (b->size)
		// {
		// 	put_max_top(b, 'b');
		// 	push(b, a, 'a');
		// }
		// return ;
	}

}

static t_node  *find_best_pal(t_stack *stack, int current_index)
{
    t_node  *iterator;
	t_node	*pal;
	int		size;
 
    iterator = stack->head;
	pal = stack->head;
	size = stack->size;
	printf("Current index = %d\n", current_index);
    while (size)
    {
		if (iterator->prev->index < current_index && iterator->index > current_index)
		{
			pal = iterator;
			break ;
		}
		else
			iterator = iterator->next;
		size--;
	}
    return (pal);
}

static int	find_pos(t_stack *stack, int index)
{
	t_node *iterator;
	int	i;

	iterator = stack->head;
	i = 0;
	while (iterator->index != index)
	{
		iterator = iterator->next;
		i++;
	}
	return (i);
}

static int	calculate_steps_to_top(t_stack *stack, int index)
{
	int	size;
	int	mid;
	int	index_pos;
	int	res;

	size = stack->size;
	mid = size / 2;
	index_pos = find_pos(stack, index);
	if (index_pos < mid)
		res = index_pos;
	else
		res = size - index_pos;
	return (res);
}

static int	calculate_moves(t_stack *a, t_stack *b, int current_index)
{
	t_node	*pal;
	int	insert_moves;
	int	pal_moves;
	int	moves;

	pal = find_best_pal(a, current_index);
	pal_moves = calculate_steps_to_top(a, pal->index);
	insert_moves = calculate_steps_to_top(b, current_index);
	moves = pal_moves + insert_moves + 1;
	printf("Moves = %d\n", moves);
	return (moves);
}

static t_node	*find_cheapest_node(t_stack *a, t_stack *b)
{
	t_node	*best_node;
	t_node	*comparator;
	int		size;
	int		group;

	best_node = b->head;
	comparator = b->head->next;
	best_node->moves = calculate_moves(a, b, best_node->index);
	size = b->size;
	group = size;
	while (size - 1)
	{
		comparator->moves = calculate_moves(a, b, comparator->index);
		if (comparator->moves < best_node->moves && comparator->index >= group)
			best_node = comparator;
		comparator = comparator->next;
		size--;
	}
	return (best_node);
}

void    optimal_insertion_sort(t_stack *b, t_stack *a)
{
    t_node	*b_top_node;
	t_node	*best_node;
	t_node	*best_pal;
    int 	mid;

    if (b->head == NULL)
		return ;
    b_top_node = b->head;
    if (b_top_node->index < find_min(a) || b_top_node->index > find_max(a))
    {
        put_min_top(a, 'a');
        push(b, a, 'a');
        return ;
    }
	mid = a->size / 2;
	best_node = find_cheapest_node(a, b);
	printf("Cheapest node is %d\n", best_node->index);
	while (b->head->index != best_node->index)
	{
		if (find_pos(b, best_node->index) <= mid) 
            rotate(b, 'b');
        else
            reverse_rotate(b, 'b');
	}
	best_pal = find_best_pal(a, best_node->index);
	printf("Best pal is %d\n", best_pal->index);
    while (a->head->index != best_pal->index)
    {
		if (find_pos(a, best_pal->index) <= mid) 
            rotate(a, 'a');
        else
            reverse_rotate(a, 'a');
    }
    push(b, a, 'a');
}

void    sort_100_and_less(t_stack *a, t_stack *b)
{
	tame_chaos(a, b);
	while (b->size)
		optimal_insertion_sort(b, a);
	while (a->head->index != 0)
		put_min_top(a, 'a');
}

// while (a->size != 1)
// {
//     if (stack_sorted_at_this_pos(a) == a->size - 1)
//         break ;
//     if (a->head->index > a->head->next->index)
//         swap(a);
//     if (a->head->index < a->head->next->index)
//         push(a, b);
//     }
//     while (b->size != 1)
//     {
//         if (b->head->index < b->head->next->index)
//             swap(b);
//         if (b->head->index > b->head->next->index)
//             push(b, a);
//     }
//     push(b, a);
//     if (stack_sorted_at_this_pos(a) != a->size - 1)
//         sort_100_and_less(a, b);
// } TROLOLOLOLO.
