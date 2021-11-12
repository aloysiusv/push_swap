/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/12 19:34:26 by lrandria         ###   ########.fr       */
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
	// t_node	*second;
    t_node  *last;
    int     best;

    if (!from->head)
        return ;
    first = from->head;
	// second = from->head->next;
    last = from->head->prev;
	// if (second->index <= group)
	// {
	// 	swap(a, 'a');
	// 	push(a, b, 'b');
	// 	return ;
	// }
    best = choose_r_rr_groups(&first, &last, group);
    if (best == 0)
        while (from->head->index != first->index)
            rotate(a, 'a');
    else if (best == 1)
        while (from->head->index != last->index)
            reverse_rotate(a, 'a');
    push(a, b, 'b');
}

static void tame_chaos(t_stack *a, t_stack *b)
{
    while (from->size != 50)    
        push_first_group(a, b, 49);
    // while (from->size != 60)
    //     push_first_group(a, b, 39);
    // while (from->size != 40)
    //     push_first_group(a, b, 59);
    // while (from->size != 20)
        // push_first_group(a, b, 79);
    while (from->size != 3)
        push_first_group(a, b, 99);
	sort_3(a);
}

static t_node  *find_best_pal(t_stack *stack, int current_index)
{
    t_node  *iterator;
 
    iterator = stack->head;
    while (!(iterator->prev->index < current_index && iterator->index > current_index))
        iterator = iterator->next;
    return (iterator);
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
	int	index_pos;
	int	res;

	size == stack->size;
	index_pos = find_pos(stack, index);
	res = size - index_pos;
	return (res)
}

static int	calculate_moves(t_stack *from, t_stack *to, int to_insert)
{
	t_node	*pal;
	int	insert_top_count;
	int	pal_top_count;
	int	moves;

	pal = find_best_pal(to, to_insert);
	pal_top_count = calculate_steps_to_top(to, pal->index);
	insert_top_count = calculate_steps_to_top(from, to_insert);
	moves = pal_top_count + insert_top_count + 1;
	return (moves);
}

static int	find_cheapest_node(t_stack *a, t_stack *b, int from_top_node, int i)
{
	int	from_second_node;
	int	from_last_node;
	int best_node;
	int j;
	int	k;

	from_second_node = from->head->next->index;
	from_last_node = from->head->prev->index;
	i = calculate_moves(a, b, from_top_node);
	j = calculate_moves(a, b, from_second_node);
	k = calculate_moves(a, b, from_last_node);
	if (i > j && i > k)
		return (best_node = from_top_node);
	else if (j > i && j > k)
		return (best_node = from_second_node);
	else if (k > j && k > j)
		return (best_node = from_last_node);
	else
		return (best_node = from_top_node);
}

void    insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
    int b_top_node;
    int best_pos;
    int mid;

    if (stack_b->head == NULL)
        return ;
    b_top_node = stack_b->head->index;
    if (b_top_node < find_min(stack_a) || b_top_node > find_max(stack_a))
    {
        put_min_top(stack_a, 'a');
        push(stack_b, stack_a, 'a');
        return ;
    }
    mid = stack_from->size / 2;
    best_pos = find_optimal_pos(stack_a, b_top_node);
    while (!(stack_from->head->prev->index < b_top_node && stack_from->head->index > b_top_node))
    {
        if (best_pos < mid) 
            rotate(stack_a, 'a');
        else
            reverse_rotate(stack_a, 'a');
    }
    push(stack_b, stack_a, 'a');
}

void    optimal_insertion_sort(t_stack *from, t_stack *to, char name)
{
    int from_top_node;
	int	from_second_node;
	int	from_last_node;
	int best_node;
    int mid;

    if (from->head == NULL)
        return ;
	if (to->size == 0)
	{
		push(from, to, name);
		push(from, to, name);
		put_max_top(to, name);
		push(from, to, name);
		put_max_top(to, name);
		return ;
	}
    from_top_node = from->head->index;
	from_second_node = from->head->next->index;
	from_last_node = from->head->prev->index; 
    if (from_top_node < find_min(to) || from_top_node > find_max(to))
    {
        put_max_top(to, name);
        push(from, to, name);
        return ;
    }
    mid = to->size / 2;
	best_node = find_cheapest_node(from, to, from_top_node, 0);
    while (!(to->head->prev->index < best_node && to->head->index > best_node))
    {
        // if (find_pos(b, ) < mid) 
        //     rotate(to, name);
        // else
        //     reverse_rotate(to, name);
    }
    push(from, to, name);
}

void    sort_100_and_less(t_stack *from, t_stack *to)
{
	// tame_chaos(a, b);
	while (from->size)
		optimal_insertion_sort(from, to, 'b');
    // while (b->size)
 	// {
    //     put_max_top(b, 'b');
	// 	push(b, a, 'a');
	// }
    // put_min_top(a, 'a');
}

// while (from->size != 1)
// {
//     if (stack_sorted_at_this_pos(a) == from->size - 1)
//         break ;
//     if (from->head->index > from->head->next->index)
//         swap(a);
//     if (from->head->index < from->head->next->index)
//         push(a, b);
//     }
//     while (b->size != 1)
//     {
//         if (b->head->index < b->head->next->index)
//             swap(b);
//         if (b->head->index > b->head->next->index)
//             push(b, a);
//         }
//     push(b, a);
//     if (stack_sorted_at_this_pos(a) != from->size - 1)
//         sort_100_and_less(a, b);
// } TROLOLOLOLO.
