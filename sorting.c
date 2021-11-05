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

static int compare_positions(t_node **first, t_node **last, int group)
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

static void	push_most_efficient(t_stack *a, t_stack *b, int group)
{
    t_node  *first;
    t_node  *last;
    int     best;

    if (!a->head)
        return ;
    first = a->head;
    last = a->head->prev;
    best = compare_positions(&first, &last, group);
    if (best == 0)
        while (a->head->index != first->index)
            rotate(a);
    else if (best == 1)
        while (a->head->index != last->index)
            reverse_rotate(a);
    if (a->head->index < find_min(b) || a->head->index > find_max(b))
        put_max_top(b);
    else
        put_min_top(b);
    push(a, b);
}

void    sort_100_and_less(t_stack *a, t_stack *b)
{
    int middle;
    int group;
    int size;

    size = a->size;
    middle = size / 2;
    group = size / 5;
    if (a->size % 2 == 1)
    {
        middle -= 1;
        group -= 1;
    }
    while (a->size != 3)
        while (b->size != size - 3)
        {
            push_most_efficient(a, b, group);
            group = group + group;
        }
    sort_3(a);
    while (b->size > 0)
    {
        put_max_top(b);
        push(b, a);
    }
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
