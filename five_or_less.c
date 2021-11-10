/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:42:54 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/10 17:34:47 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_2(t_stack *stack)
{
    if (stack->head->index > stack->head->next->index)
		swap(stack, 'a');
}

void	sort_3(t_stack *stack)
{
    size_t min_pos;
    size_t max_pos;

    min_pos = find_min_pos(stack);
    max_pos = find_max_pos(stack);
    if (min_pos == 0 && max_pos == 1)
    {
        swap(stack, 'a');
        rotate(stack, 'a');
    }
    if (min_pos == 1 && max_pos == 0)
        rotate(stack, 'a');
    if (min_pos == 1 && max_pos == 2)
        swap(stack, 'a');
    if (min_pos == 2 && max_pos == 0)
    {
        swap(stack, 'a');
        reverse_rotate(stack, 'a');
    }
    if (min_pos == 2 && max_pos == 1)
        reverse_rotate(stack, 'a');
 }

static void sort_4(t_stack *a, t_stack *b)
{
    put_min_top(a, 'a');
    push(a, b, 'a');
    sort_3(a);
    push(b, a, 'a');
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
        put_min_top(a, 'a');
        push(a, b, 'b');
        put_min_top(a, 'a');
        push(a, b, 'b');
        sort_3(a);
        push(b, a, 'a');
        push(b, a, 'a');
    }
}