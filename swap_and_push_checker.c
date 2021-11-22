/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:59:36 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/22 18:59:40 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (stack->head == NULL)
		return ;
	tmp_value = stack->head->value;
	tmp_index = stack->head->index;
	if (stack->size >= 2)
	{
		stack->head->value = stack->head->next->value;
		stack->head->next->value = tmp_value;
		stack->head->index = stack->head->next->index;
		stack->head->next->index = tmp_index;
	}
}

void	swap_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL || b->head == NULL)
		return ;
	swap(a);
	swap(b);
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
	if (node == NULL)
		return ;
	else
	{
		add_top_node(receiving, node);
		pushing->size--;
		receiving->size++;
	}
}
