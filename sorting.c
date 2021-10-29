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
    printf("Sort 2 done.\n");
}

static void	sort_3(t_stack *stack)
{
    size_t  pos_min;

    pos_min = find_min_pos(stack);
    if (pos_min == 0)
    {
        swap(stack);
        rotate(stack);
        printf("Sort 3 done.\n");
        return ;
    }
    if (pos_min == 1)
    {
        if (stack->head->next->index == 0)
        {
            swap(stack);
            printf("Sort 3 done.\n");
            return ;
        }
        else
        {
            reverse_rotate(stack);
            printf("Sort 3 done.\n");
            return ;
        }
    }
    if (pos_min == 2)
    {
        if (stack->head->next->index == 0)
        {
            rotate(stack);
            printf("Sort 3 done.\n");
            return ;
        }
        else
        {
            swap(stack);
            reverse_rotate(stack);
            printf("Sort 3 done.\n");
            return ;
        }
    }
 }

void    sort_4(t_stack *a, t_stack *b)
{
    put_min_top(a);
    push(a, b);
    sort_3(a);
    push(b, a);
    printf("Sort 4 done.\n");
}

void	sort_5_and_less(t_stack *a, t_stack *b)
{
    (void)b;
    if (a->size == 2)
    {
        sort_2(a);
        return ;
    }
    if (a->size == 3)
    {
        sort_3(a);
        return ;
    }
    if (a->size == 4)
    {
        sort_4(a, b);
        return ;
    }

}

// void	sort_100_and_less(t_stack *a, t_stack *b)
// {

// }

// void	sort_500_and_less(t_stack *a, t_stack *b)
// {

// }
