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
    else if (best == 1)
        while (a->head->index != last->index)
            reverse_rotate(a, 'a');
    push(a, b, 'b');
}

static void tame_chaos(t_stack *a, t_stack *b)
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
        push_first_group(a, b, 99);
}

static int  find_optimal_pos(t_stack *a, int current_index)
{
    int     best;
    t_node  *next;
 
    best = 0;
    next = a->head;
    while (!(next->prev->index < current_index && next->index > current_index))
    {
        next = next->next;
        best++;
    }
    return (best);
}

void    insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
    int b_top_node;
    int best_pos;
    int mid;
    
    if (stack_a->head == NULL)
    {
        push(stack_b, stack_a, 'a');
        push(stack_b, stack_a, 'a');
        push(stack_b, stack_a, 'a');
        sort_3(stack_a);
        return ;
    }
    if (stack_b->head == NULL)
        return ;
    b_top_node = stack_b->head->index;
    if (b_top_node < find_min(stack_a) || b_top_node > find_max(stack_a))
    {
        put_min_top(stack_a, 'a');
        push(stack_b, stack_a, 'a');
        return ;
    }
    mid = stack_a->size / 2;
    best_pos = find_optimal_pos(stack_a, b_top_node);
    while (!(stack_a->head->prev->index < b_top_node && stack_a->head->index > b_top_node))
    {
        if (best_pos < mid) 
            rotate(stack_a, 'a');
        else
            reverse_rotate(stack_a, 'a');
    }
    push(stack_b, stack_a, 'a');
}

void    sort_100_and_less(t_stack *a, t_stack *b)
{
    tame_chaos(a, b);
    while (b->size)
        insertion_sort(a, b);
    while (a->head->index != 0)
        reverse_rotate(a, 'a'); //or rotate if better

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
// } TROLOLOLOLO.
