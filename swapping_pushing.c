/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping_pushing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:53:29 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:53:29 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c)
{
	t_node	tmp[1];

	if (stack->size >= 2)
	{
		tmp->num = stack->head->num;
		stack->head->num = stack->head->next->num;
		stack->head->next->num = tmp->num;
		if (c == 'a')
			write(1, "sa\n", 3);
		if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}

void	push(t_stack *receiving, t_stack *pushing, char pushed_on)
{
	if (pushing->head != NULL)
	{
		t_node	*tmp;

		if (pushing->size > 1)
			pushing->head = pushing->head->next;
		tmp = add_bottom_node(receiving->head, pushing->head->num);
		printf("Node [%d] pushed, now will be deleted.", pushing->head->num);
		delete_node(pushing->head);
		pushing->size = pushing->size - 1;
		receiving->size = receiving->size + 1;
	}
	if (pushed_on == 'a')
		write(1, "pa\n", 3);
	if (pushed_on == 'b')
		write(1, "pb\n", 3);
}