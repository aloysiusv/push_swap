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

static t_node	*pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	if (stack->head->next == stack->head)
		stack->head = NULL;
	else
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head = stack->head->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

static void	help_push(t_stack *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev = stack->head->prev;
		node->next = stack->head;
		stack->head->prev->next = node;
		stack->head->prev = node;
	}
	stack->head = node;
}

void	push(t_stack *pushing, t_stack *receiving, char pushed_on)
{
	t_node	*node;

	if ((node = pop(pushing)))
		help_push(receiving, node);
	printf("Node [%d] has been pushed.\n", receiving->head->num);
	pushing->size--;
	receiving->size++;
	if (pushed_on == 'a')
		write(1, "pa\n", 3);
	if (pushed_on == 'b')
		write(1, "pb\n", 3);
}
