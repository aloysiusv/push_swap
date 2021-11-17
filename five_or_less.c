/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:42:54 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/17 16:52:43 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_2(t_stack *stack)
{
    if (stack->head->index > stack->head->next->index)
		swap(stack);
}

void	sort_3(t_stack *stack)
{
    size_t min_pos;
    size_t max_pos;

    min_pos = find_pos(stack, find_min(stack));
    max_pos = find_pos(stack, find_max(stack));
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