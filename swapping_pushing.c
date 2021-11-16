/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping_pushing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:214 21:53:29 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:53:29 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	if (stack->size >= 2)
	{
		stack->head->value = stack->head->next->value;
		stack->head->next->value = tmp->value;
		stack->head->index = stack->head->next->index;
		stack->head->next->index = tmp->index;
		if (stack->name == 'a' && stack->ss <= 0)
			write(1, "sa\n", 3);
		if (stack->name == 'b' && stack->ss <= 0)
			write(1, "sb\n", 3);
		stack->count_op++;
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	a->count_op--;
}

static t_node	*pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	if (stack->head != NULL)
	{
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
	}
	return (tmp);
}

static void	add_top_node(t_stack *stack, t_node *node)
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

void	push(t_stack *pushing, t_stack *receiving)
{
	t_node	*node;

	node = pop(pushing);
	if (node != NULL)
	{
		add_top_node(receiving, node);
		pushing->size--;
		receiving->size++;
		if (receiving->name == 'a')
			write(1, "pa\n", 3);
		if (receiving->name == 'b')
			write(1, "pb\n", 3);
		printf("Node [%d] has been pushed.\n", receiving->head->value);
		pushing->count_op++;
	}
}
