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

void    sort_4(t_stack *a, t_stack *b)
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

// void	sort_100_and_less(t_stack *a, t_stack *b)
// {

// }

// void	sort_500_and_less(t_stack *a, t_stack *b)
// {

// }
