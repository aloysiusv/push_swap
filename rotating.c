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

void	rotate(t_stack *stack, char c)
{
	t_node *tmp;
	
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack *stack, t_stack *other_stack)
{
	rotate(stack);
	rotate(other_stack);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack *stack, char c)
{
	t_node	*tmp;
	
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack *stack, t_stack *other_stack)
{
	reverse_rotate(stack);
	reverse_rotate(other_stack);
	write(1, "rrr\n", 4);
}