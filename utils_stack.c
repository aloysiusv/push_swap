/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:45:19 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:45:19 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_next_min_value(t_stack *a)
{
	size_t	size;
	t_node	*min;
	t_node	*comparator;

	if (a->head == NULL)
		return (NULL);
	size = a->size;
	if (size == 1)
		return (min = a->head);
	else
	{
		min = a->head;
		comparator = a->head->next;
		while (size)
		{
			if (min->value > comparator->value && comparator->index == -1)
				min = comparator;
			if (min->value < comparator->value && min->index > -1)
				min = comparator;
			comparator = comparator->next;
			size--;
		}
	}
	return (min);
}

static void		init_index(t_stack *a)
{
	int		index;
	size_t	size;
	t_node	*min;

	index = 0;
	size = a->size;
	while (size)
	{
		min = find_next_min_value(a);
		min->index = index;
		index++;
		size--;
	}
}

static int		fill_stack_more(size_t size, t_node **node, char **input)
{
	t_node	*new;
	size_t	i;

	i = 2;
	while (i < size)
	{
		new = add_bottom_node(*node, ft_atoi(input[i])); 
		if (new == NULL)
			return (-1);
		*node = (*node)->next;
		i++;
	}
	return (0);
}

int				init_stacks(t_stack *a, t_stack *b, size_t size, char **input)
{
	t_node	*node;

	a->size = size;
	b->size = 0;
	a->count_op = 0;
	b->count_op = 0;
	b->head = NULL;
	a->head = create_node(ft_atoi(input[0]));
	node = add_bottom_node(a->head, ft_atoi(input[1]));
	if (a->head == NULL ||node == NULL)
		return (-1);
	a->head->next = node;
	if (a->size > 2)
		if (fill_stack_more(size, &node, input) == -1)
			return (-1);
	a->head->prev = node;
	node->next = a->head;
	init_index(a);
	return (0);
}

void			delete_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->size)
	{
		tmp = stack->head;
	  	stack->head = stack->head->next;
	  	printf("Node [%d] is next to be deleted.\n", tmp->value);
	  	delete_node(tmp);
		stack->size--;
	}
	if (stack != NULL)
		free(stack);
	printf("Stack has been deleted.\n");
}
