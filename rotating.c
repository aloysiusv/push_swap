/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:27:26 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/01 02:27:26 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_node_to_bottom(t_stack *stack, char c)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	// printf("stack->head before ra = %d\n", stack->head->num);
	stack->head = stack->head->next;
	// printf("stack->head after ra = %d\n", stack->head->num);
	stack->head->prev = tmp;
	// printf("stack->head->prev after ra = %d\n", stack->head->prev->num);
	if (c == 'a')
		write(1, "ra\n", 4);
	if (c == 'b')
		write(1, "rb\n", 4);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	top_node_to_bottom(a, 0);
	top_node_to_bottom(b, 0);
	write(1, "rr\n", 3);
}

void	bottom_node_to_top(t_stack *stack, char c)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = stack->head->prev;
	stack->head->next = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	bottom_node_to_top(a, 0);
	bottom_node_to_top(b, 0);
	write(1, "rrr\n", 4);
}
