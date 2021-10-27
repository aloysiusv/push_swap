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
    if (stack->size == 2)
		if (stack->head->index > stack->head->next->index)
			swap(stack, 'a');
}

static void	sort_2_3(t_stack *stack)
{
    if (stack->size == 2)
        sort_2(stack);
    if (stack->size == 3)
	{
        if (stack->head->index == 0)
        {
            swap(stack, 'a');
            rotate(stack, 'a');
        }
        if (stack->head->index == 1)
        {
            if (stack->head->next->index == 0)
                swap(stack, 'a');
            else
                reverse_rotate(stack, 'a');
        }
        if (stack->head->index == 2)
        {
            if (stack->head->next->index == 0)
                rotate(stack, 'a');
            else
            {
                swap(stack, 'a');
                reverse_rotate(stack, 'a');
            }
        }
    }
 }

void	sort_5_and_less(t_stack *a, t_stack *b)
{
    (void)b;
    sort_2_3(a);
}

// void	sort_100_and_less(t_stack *a, t_stack *b)
// {

// }

// void	sort_500_and_less(t_stack *a, t_stack *b)
// {

// }
