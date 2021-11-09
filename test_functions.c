/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:45:41 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/09 21:26:28 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stack
{
	char	name;
	int		size;
	size_t	count_op;
	t_node	*head;
	int		swap;
	int		rotate;
	int		rev_rotate;
}				t_stack;

int	put_min_top(t_stack *stack)
{
	int	size;
	int	min;
	int	moves;

	size = stack->size;
	if (!size)
		return (-1);
	min = find_min_pos(stack);
	moves = 0;
	if (min == 0)
		return (0);
	if (min == 1)
	{
		swap(stack);
		return (1);
	}
	while (find_min_pos(stack) != 0)
	{
		if (min + 1 > size / 2)
			reverse_rotate(stack);
		if (min + 1 <= size / 2)
			rotate(stack);
		moves++;
	}
	return (moves);
}

int	put_max_top(t_stack *stack)
{
	int	max;

	if (!stack->size)
		return ;
	max = find_max_pos(stack);
	if (max == 0)
		return ;
	if (max == 1)
		swap(stack);
	while (find_max_pos(stack) != 0)
	{
		if (max + 1 > stack->size / 2)
			reverse_rotate(stack);
		if (max + 1 <= stack->size / 2)
			rotate(stack);
	}
}



// static int find_best_node_to_push(t_node **first, t_node **last, int half)
// {
//     int pos_first;
//     int pos_last;
//     int i;

//     i = 0;
//     while (i < half)
//     {
//         if ((*first)->index >= 0 && (*first)->index < half)
//             break ;
//         *first = (*first)->next;
//         i++;
//     }
//     pos_first = i;
//     i = 0;
//     while (i < half)
//     {
//         if ((*last)->index >= 0 && (*last)->index < half)
//             break ;
//         *last = (*last)->prev;
//         i++;
//     }
//     pos_last = i;
//     if (pos_first <= pos_last)
//         return (0);
//     return (1);
// }
// static void sort_half(t_stack *a, t_stack *b)
// {
//     while (b->size)
//     {
//         put_max_top(b);
//         push(b, a);
//     }
// }
// static void	push_first_half(t_stack *a, t_stack *b, int half)
// {
//     t_node  *first;
//     t_node  *last;
//     int     best;

//     if (!a->head)
//         return ;
//     first = a->head;
//     last = a->head->prev;
//     best = find_best_node_to_push(&first, &last, half);
//     if (best == 0)
//         while (a->head->index != first->index)
//             rotate(a);
//     else if (best == 1)
//         while (a->head->index != last->index)
//             reverse_rotate(a);
//     push(a, b);
// }

// static void push_half(t_stack *a, t_stack *b)
// {
//     int half;

//     half = a->size / 2;
//     while (a->size != half)
//         push_first_half(a, b, half);
//     // while (a->size)
//     //     push(a, b);
// }

// static void push_second_half(t_stack *a, t_stack *b)
// {
//     int idx_min;
//     int idx_max;
//     int mid;

//     idx_min = (a->size / 2) - 1;
//     idx_max = a->size - 1;
//     mid = a->size / 2;
//     while (a->size != mid)
//     {   
//         if (a->head->index >= idx_min && a->head->index <= idx_max)
//             push(a, b);
//         else
//             rotate(a);
//     }
//     // while (a->size)
//     //     push(a, b);
// }

// void    push_half_chaotic(t_stack *a, t_stack *b)
// {
//    int half;
   
//    half = a->size / 2;
//    while (b->size != half)
//         push(a, b);
// }

void    check_double_actions(t_stack *a, t_stack *b, int min_a, int max_b)
{
    int i;
    int j;

    i = put_min_top(a);
    j = put_max_top(b);



}

void    create_two_semi_sorted_stacks(t_stack *a, t_stack *b)
{
    int a_idx_min;
    int a_idx_max;
    int b_idx_max;
    int b_idx_min;

    a_idx_min = (a->size / 2); // a = 50 - 99;
    a_idx_max = a->size - 1;
    b_idx_min = 0;                  // b = 0 - 49
    b_idx_max = (a->size / 2) - 1;
    check_double_actions(a, b, a_idx_min, b_idx_max);
    if (a->head->index <= a_idx_min)
        push(a, b)

}

void    sort_100_and_less(t_stack *a, t_stack *b)
{
    push_half_chaotic(a, b);
    create_two_semi_sorted_stacks(a, b);
    insertion_sort_magic(a, b);

    
    
    
    
    
    
    
    
    
    
    
    
    // push_half(a, b);
    // sort_half(a, b);
    // push_second_half(a, b);
//     while (b->size)
//          insertion_sort(a, b);    
}

// static void rotate_to_optimal_pos(t_stack *a, int current_index)
// {
//     t_node  *iterator;
//     int     mid; // just half my stack
//     int     idx_mid; // the index at that position
//     int     i;

//     iterator = a->head;
//     mid = a->size / 2;
//     if (a->size % 2 == 1)
//         mid += 1;
//     idx_mid = 0;
//     i = 0;
//     while (i != mid) // loop to identify which index is at the mid
//     {
//         idx_mid = iterator->index;
//         iterator = iterator->next;
//         i++;
//     }
//     if (current_index < idx_mid) // it always have to be 54 > 86 > 98, if you want to push 86.
//         while (a->head->prev->index > current_index && a->head->index < current_index)
//             rotate(a);
//     else
//         while (a->head->prev->index > current_index && a->head->index < current_index)
//             reverse_rotate(a);
// }

// void    insertion_sort(t_stack *stack_a, t_stack *stack_b)
// {
//     int b_first; 
//     int b_second;
//     int a_first;
//     int a_last;
    
//     if (stack_a->head == NULL)
//     {
//         push(stack_b, stack_a);
//         push(stack_b, stack_a);
//         sort_2(stack_a);
//         return ;
//     }
//     if (stack_b->head == NULL)
//         return ;
//     b_first = stack_b->head->index;
//     b_second = stack_b->head->next->index;
//     a_first = stack_a->head->index;
//     a_last = stack_a->head->prev->index;
//     if (b_first < b_second)
//     {
//         swap(stack_b); //questionable efficiency
//         printf("Swapped B and Bnext\n");
//     }
//     if (b_first < find_min(stack_a) || b_first > find_max(stack_a))
//     {
//         put_min_top(stack_a);
//         push(stack_b, stack_a);
//         printf("Put min top!\n");
//         return ;
//     }
//     if (b_first < a_first)
//     {
//         if (b_first < a_last)
//             rotate_to_optimal_pos(stack_a, b_first); // 89 97 71 72 82, wanna push 77
//         // you have to RA or RRA until a->last < 77 AND a->first > 77
//         // go figure whether to RA or RRA by finding out the range in index (here 72 - 82. aka 2 - 10)
//         push(stack_b, stack_a);
//         printf("B was < to A!\n");
//         return ;
//     }
//     if (b_first > a_first)
//     {
//         if (b_first < a_last)
//             rotate_to_optimal_pos(stack_a, b_first);
//         push(stack_b, stack_a);
//         printf("B was > to A!\n");
//         return ;
//     }
//     printf("Error?\n");
// }  

    
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