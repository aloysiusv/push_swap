/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/01 19:15:34 by lrandria         ###   ########.fr       */
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

static void sort_2(t_stack *stack)
{
    if (stack->head->index > stack->head->next->index)
		swap(stack);
}

static void	sort_3(t_stack *stack)
{
    size_t min_pos;
    size_t max_pos;

    min_pos = find_min_pos(stack);
    max_pos = find_max_pos(stack);
    if (min_pos == 0 && max_pos == 1)
    {
        swap(stack);
        rotate(stack);
    }
    if (min_pos == 1 && max_pos == 0)
        rotate(stack);
    if (min_pos == 1 && max_pos == 2)
        swap(stack);
    if (min_pos == 2 && max_pos == 0)
    {
        swap(stack);
        reverse_rotate(stack);
    }
    if (min_pos == 2 && max_pos == 1)
        reverse_rotate(stack);
 }

static void sort_4(t_stack *a, t_stack *b)
{
    put_min_top(a);
    push(a, b);
    sort_3(a);
    push(b, a);
}

void	sort_5_and_less(t_stack *a, t_stack *b)
{
    if (a->size == 2)
        sort_2(a);
    if (a->size == 3)
        sort_3(a);
    if (a->size == 4)
        sort_4(a, b);
    if (a->size == 5)
    {
        put_min_top(a);
        push(a, b);
        put_min_top(a);
        push(a, b);
        sort_3(a);
        push(b, a);
        push(b, a);
    }
}

static int find_best_node_to_push(t_node **first, t_node **last, int half)
{
    int pos_first;
    int pos_last;
    int i;

    i = 0;
    while (i < half)
    {
        if ((*first)->index >= 0 && (*first)->index < half)
            break ;
        *first = (*first)->next;
        i++;
    }
    pos_first = i;
    i = 0;
    while (i < half)
    {
        if ((*last)->index >= 0 && (*last)->index < half)
            break ;
        *last = (*last)->prev;
        i++;
    }
    pos_last = i;
    if (pos_first <= pos_last)
        return (0);
    return (1);
}

static void	push_first_half(t_stack *a, t_stack *b, int half)
{
    t_node  *first;
    t_node  *last;
    int     best;

    if (!a->head)
        return ;
    first = a->head;
    last = a->head->prev;
    best = find_best_node_to_push(&first, &last, half);
    if (best == 0)
        while (a->head->index != first->index)
            rotate(a);
    else if (best == 1)
        while (a->head->index != last->index)
            reverse_rotate(a);
    push(a, b);
}

static void push_halves(t_stack *a, t_stack *b)
{
    int half;

    half = a->size / 2;
    while (a->size != half)
        push_first_half(a, b, half);
    while (a->size)
        push(a, b);
}

static void rotate_to_optimal_pos(t_stack *a, int current_index)
{
    t_node  *iterator;
    int     mid; // just half my stack
    int     idx_mid; // the index at that position
    int     i;

    iterator = a->head;
    mid = a->size / 2;
    if (a->size % 2 == 1)
        mid += 1;
    idx_mid = 0;
    i = 0;
    while (i != mid) // loop to identify which index is at the mid
    {
        idx_mid = iterator->index;
        iterator = iterator->next;
        i++;
    }
    if (current_index < idx_mid) // it always have to be 54 > 86 > 98, if you want to push 86.
        while (a->head->prev->index > current_index && a->head->index < current_index)
            rotate(a);
    else
        while (a->head->prev->index > current_index && a->head->index < current_index)
            reverse_rotate(a);
}

void    insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
    int b_first; 
    int b_second;
    int a_first;
    int a_last;
    
    if (stack_a->head == NULL)
    {
        push(stack_b, stack_a);
        push(stack_b, stack_a);
        sort_2(stack_a);
        return ;
    }
    if (stack_b->head == NULL)
        return ;
    b_first = stack_b->head->index;
    b_second = stack_b->head->next->index;
    a_first = stack_a->head->index;
    a_last = stack_a->head->prev->index;
    if (b_first < b_second)
    {
        swap(stack_b); //questionable efficiency
        printf("Swapped B and Bnext\n");
    }
    if (b_first < find_min(stack_a) || b_first > find_max(stack_a))
    {
        put_min_top(stack_a);
        push(stack_b, stack_a);
        printf("Put min top!\n");
        return ;
    }
    if (b_first < a_first)
    {
        if (b_first < a_last)
            rotate_to_optimal_pos(stack_a, b_first); // 89 97 71 72 82, wanna push 77
        // you have to RA or RRA until a->last < 77 AND a->first > 77
        // go figure whether to RA or RRA by finding out the range in index (here 72 - 82. aka 2 - 10)
        push(stack_b, stack_a);
        printf("B was < to A!\n");
        return ;
    }
    if (b_first > a_first)
    {
        if (b_first < a_last)
            rotate_to_optimal_pos(stack_a, b_first);
        push(stack_b, stack_a);
        printf("B was > to A!\n");
        return ;
    }
    printf("Hello\n");
}  

void    sort_100_and_less(t_stack *a, t_stack *b)
{
    push_halves(a, b);
    while (b->size)
        insertion_sort(a, b);
    
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
//         }
//     push(b, a);
//     if (stack_sorted_at_this_pos(a) != a->size - 1)
//         sort_100_and_less(a, b);
// }

// void	sort_500_and_less(t_stack *a, t_stack *b)
// {

// }
