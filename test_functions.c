/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/17 20:41:46 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int choose_r_rr_groups(t_node **first, t_node **last, int idx_min, int idx_max)
{
    int pos_first;
    int pos_last;
    int i;

    i = 0;
    while (i < idx_max)
    {
        if ((*first)->index >= idx_min && (*first)->index < idx_max)
            break ;
        *first = (*first)->next;
        i++;
    }
    pos_first = i;
    i = 0;
    while (i < idx_max)
    {
        if ((*last)->index >= idx_min && (*last)->index < idx_max)
            break ;
        *last = (*last)->prev;
        i++;
    }
    pos_last = i;
    if (pos_first <= pos_last)
        return (0);
    return (1);
}

static void	push_group(t_stack *a, t_stack *b, int idx_min, int idx_max)
{
    t_node  *first;
    t_node  *last;
    int     best;

    if (!a->head)
        return ;
    first = a->head;
    last = a->head->prev;
    best = choose_r_rr_groups(&first, &last, idx_min, idx_max);
    if (best == 0)
        while (a->head->index != first->index)
            rotate(a);
    else
        while (a->head->index != last->index)
            reverse_rotate(a);
    push(a, b);
}

static void tame_chaos(t_stack *a, t_stack *b)
{
    int	mid;

	if (a->size < 100)
	{
		mid = a->size / 2;
		if (a->size % 2 != 0)
		{
			mid += 1;
			while (a->size != mid)    
        		push_group(a, b, 0, mid - 1);
    		while (a->size)
				push(a, b);
			return ;
		}
		while (a->size != mid)    
        	push_group(a, b, 0, mid);
    	while (a->size)
			push(a, b);
		// sort_3(a);
		// printf("Head = %d, Second = %d, Last = %d\n", a->head->index, 
		// a->head->next->index, a->head->prev->index);
	// 	while (a->size)
	// 	{
	// 		put_min_top(a);
	// 		push(a, b);
	// 	}
	}
 	if (a->size == 100)
	{
		while (a->size != 50)
			push_group(a, b, 0, 69);
		// while (a->size != 80)    
        // 	push_group(a, b, 19);
    	// while (a->size != 60)
        // 	push_group(a, b, 39);
    	// while (a->size != 40)
        // 	push_group(a, b, 59);
    	// while (a->size != 20)
        // 	push_group(a, b, 79);
   		while (a->size)
			push(a, b);
		// while (b->size)
		// {
		// 	put_max_top(b);
		// 	push(b, a);
		// }
		// return ;
	}
	if (a->size == 500)
	{
		// while (a->size != 455)    
        // 	push_group(a, b, 0, 44);
    	// while (a->size != 410)
        // 	push_group(a, b, 45, 89);
    	// while (a->size != 365)
        // 	push_group(a, b, 90, 134);
    	// while (a->size != 320)
        // 	push_group(a, b, 135, 179);
		// while (a->size != 275)
        // 	push_group(a, b, 180, 224);
		// while (a->size != 230)
        // 	push_group(a, b, 225, 269);
		// while (a->size != 185)
        // 	push_group(a, b, 270, 314);
		// while (a->size != 140)
        // 	push_group(a, b, 315, 359);
		// while (a->size != 95)
        // 	push_group(a, b, 360, 404);
		// while (a->size != 50)
        // 	push_group(a, b, 405, 449);
		while (a->size != 334)
        	push_group(a, b, 0, 200);
		while (a->size != 166)
        	push_group(a, b, 0, 400);
   		while (a->size)
			push(a, b);
		// while (b->size)
		// {
		// 	put_max_top(b);
		// 	push(b, a);
		// }
		// return ;
	}

}

static t_node  *find_senpai(t_stack *stack, int current_index)
{
    t_node  *iterator;
	t_node	*senpai;
	int		size;

	iterator = stack->head;
	senpai = stack->head;
	size = stack->size;
    while (size)
    {
		if (iterator->prev->index < current_index && iterator->index > current_index)
		{
			senpai = iterator;
			break ;
		}
		iterator = iterator->next;
		size--;
	}
    return (senpai);
}

static int	calculate_steps_to_top(t_stack *stack, int index)
{
	int	index_pos;
	int	res;

	index_pos = find_pos(stack, index);
	if (index_pos <= stack->size / 2)
		res = index_pos;
	else
		res = stack->size - index_pos;
	return (res);
}

static int	calculate_moves(t_stack *a, t_stack *b, int current_index)
{
	t_node	*senpai;
	int	index_moves;
	int	senpai_moves;
	int	moves;

	// printf("Current index is = %d\n", current_index);
	if (a->head == NULL || b->head == NULL)
		return (0);
	senpai = find_senpai(a, current_index);
	// printf("Senpai is = %d\n", senpai->value);
	senpai_moves = calculate_steps_to_top(a, senpai->index);
	// printf("Senpai moves is = %d\n", senpai_moves);
	index_moves = calculate_steps_to_top(b, current_index);
	// printf("Index moves is = %d\n", index_moves);
	moves = senpai_moves + index_moves + 1;
	// printf("Moves = %d\n", moves);
	return (moves);
}

static t_node	*find_cheapest_node(t_stack *a, t_stack *b)
{
	t_node	*best_node;
	t_node	*comparator;
	int		size;
	int		group;

	best_node = b->head;
	comparator = b->head->next;
	best_node->moves = calculate_moves(a, b, best_node->index);
	size = b->size;
	group = size;
	while (size - 1)
	{
		comparator->moves = calculate_moves(a, b, comparator->index);
		if (comparator->moves < best_node->moves)
			best_node = comparator;
		comparator = comparator->next;
		size--;
	}
	return (best_node);
}

static int	is_new_min_max(t_stack *a, t_stack *b, int current_index)
{
	if (current_index < find_min(a) || current_index > find_max(a))
    {
		while (b->head->index != current_index)
		{
			if (find_pos(b, current_index) <= (b->size + 1) / 2)
            	rotate(b);	
        	else
            	reverse_rotate(b);
		}
        put_min_top(a);
        push(b, a);
		return (1); 
	}
	return (0);
}

static void	stock_rotation_flags(t_stack *a, t_stack *b, int best_index, int senpai_index)
{
	t_node	*b_iterator;
	t_node	*a_iterator;
	int		best_pos;
	int		senpai_pos;
	
	b_iterator = b->head;
	a_iterator = a->head;
	best_pos = find_pos(b, best_index);
	senpai_pos = find_pos(a, senpai_index);
	if (best_pos <= b->size / 2)
	{
		while (b_iterator->index != best_index)
		{
			b->rotate++;	
			b_iterator = b_iterator->next;
		}
		// printf("b->rotate = %d\n", b->rotate);
	}
	else
	{
		while (b_iterator->index != best_index)
		{
			b->reverse_rotate++;	
			b_iterator = b_iterator->prev;
		}
		// printf("b->reverse_rotate = %d\n", b->reverse_rotate);
	}
	if (senpai_pos <= a->size / 2)
	{
		while (a_iterator->index != senpai_index)
		{
			a->rotate++;
			a_iterator = a_iterator->next;
		}
		// printf("a->rotate = %d\n", a->rotate);
	}
	else
	{
		while (a_iterator->index != senpai_index)
		{
			a->reverse_rotate++;	
			a_iterator = a_iterator->prev;
		}
		// printf("a->reverse_rotate = %d\n", a->reverse_rotate);
	}
}

static void	apply_rot_equal(t_stack *a, t_stack *b)
{
	if (b->rotate == a->rotate)
	{
		a->rr++;
		b->rr++;
		while (b->rotate && a->rotate)
		{
			rotate_both(a, b);
			b->rotate--;
			a->rotate--;
		}
		a->rr = 0;
		b->rr = 0;
        // printf("Rot equal\n");
	}
	if (b->reverse_rotate == a->reverse_rotate)
	{
		a->rrr++;
		b->rrr++;
		while (b->reverse_rotate && a->reverse_rotate)
		{
			reverse_rotate_both(a, b);
			b->reverse_rotate--;
			a->reverse_rotate--;
		}
		a->rrr = 0;
		b->rrr = 0;
        // printf("Rev rot equal\n");

	}
}

static void	apply_rot_inferior(t_stack *a, t_stack *b)
{
	if (b->rotate < a->rotate)
	{
		a->rr++;
		b->rr++;
		while (b->rotate)
		{
			rotate_both(a, b);
			b->rotate--;
			a->rotate--;
		}
		a->rr = 0;
		b->rr = 0;
        // printf("Rot b inferior\n");
		while (a->rotate)
		{
			rotate(a);
			a->rotate--;
		}
        // printf("Do rest rot a\n");
	}
}

static void	apply_rot_superior(t_stack *a, t_stack *b)
{
	if (b->rotate > a->rotate)
	{
		a->rr++;
		b->rr++;
		while (a->rotate)
		{
			rotate_both(a, b);
			b->rotate--;
			a->rotate--;
		}
		a->rr = 0;
		b->rr = 0;
        // printf("Rot b superior\n");
		while (b->rotate)
		{
			rotate(b);
			b->rotate--;
		}
        // printf("Do rest rot b\n");
	}
}

static void	apply_rev_rot_inferior(t_stack *a, t_stack *b)
{
	if (b->reverse_rotate < a->reverse_rotate)
	{
		a->rrr++;
		b->rrr++;
		while (b->reverse_rotate)
		{
			reverse_rotate_both(a, b);
			b->reverse_rotate--;
			a->reverse_rotate--;
		}
		a->rrr = 0;
		b->rrr = 0;
        // printf("Rev rot b inferior\n");
		while (a->reverse_rotate)
		{
			reverse_rotate(a);
			a->reverse_rotate--;
		}
        // printf("Do rest rev rot a\n");
	}
}

static void	apply_rev_rot_superior(t_stack *a, t_stack *b)
{
	if (b->reverse_rotate > a->reverse_rotate)
	{
		a->rrr++;
		b->rrr++;
		while (a->reverse_rotate)
		{
			reverse_rotate_both(a, b);
			b->reverse_rotate--;
			a->reverse_rotate--;
		}
		a->rrr = 0;
		b->rrr = 0;
        // printf("Rev rot b superior\n");
		while (b->reverse_rotate)
		{
			reverse_rotate(b);
			b->reverse_rotate--;
		}
        // printf("Do rest rev rot b\n");
	}
}

void    optimal_insertion_sort(t_stack *b, t_stack *a)
{
	t_node	*best_node;
	t_node	*senpai;

    if (a->head == NULL || b->head == NULL)
	{
		if (a->head == NULL)
			push(b, a);
		return ;
	}
	best_node = find_cheapest_node(a, b);
	// printf("Cheapest node is %d\n", best_node->value);
	if (is_new_min_max(a, b, best_node->index) == 1)
		return ;
	senpai = find_senpai(a, best_node->index);
	// printf("Best senpai is %d\n", senpai->value);
	stock_rotation_flags(a, b, best_node->index, senpai->index);
	apply_rot_equal(a, b);
	apply_rot_inferior(a, b);
	apply_rot_superior(a, b);
	apply_rev_rot_inferior(a, b);
	apply_rev_rot_superior(a, b);
	push(b, a);
}

void    sort_100_and_less(t_stack *a, t_stack *b)
{
	tame_chaos(a, b);
	while (b->size)
		optimal_insertion_sort(b, a);
	while (a->head->index != 0)
		put_min_top(a);
	// if (is_stack_sorted(a) == OK)
		// write(1, "OK\n", 3);
	// else
		// write(1, "KO\n", 3);
}
