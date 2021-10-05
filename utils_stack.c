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

int		init_stack(t_stack *a, t_stack *b, size_t nb_of_elements, char **input)
{
	t_node	*node;
	t_node	*tmp;
	size_t	i;

	i = 0;
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;
	a->size = nb_of_elements;
	a->head = create_node(ft_atoi(input[i]));
	if (a->head == NULL)
		return (-1); 
	i = 1;
	node = add_bottom_node(a->head, ft_atoi(input[i]));
	if (node == NULL)
		return (-1);
	a->head->prev = a->head;
	a->head->next = node;
	while (++i < nb_of_elements)
	{
		tmp = add_bottom_node(node, ft_atoi(input[i])); 
		if (tmp == NULL)
			return (-1);
		node->next = tmp;
		tmp = tmp->next;
		node = node->next;
	}
	a->tail = node;
	a->tail->next = a->head;
	return (0);
}

t_bool	is_stack_sorted(t_stack *stack)
{
	t_node	*iterator;
	t_node	*comparator;

	iterator = stack->head;
	comparator = stack->head->next;
	while (iterator != stack->tail)
	{
		if (iterator->num > comparator->num)
			return (NOT_OK);
		iterator = iterator->next;
		comparator = comparator->next;
	}
	return (OK);
}

void	delete_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;
	
	if (stack->size > 1)
	{
		current = stack->head;
		while (current != stack->tail)
		{
	  	tmp = current;
      	current = current->next;
	  	printf("Node [%d] is next to be deleted.\n", tmp->num);
	  	delete_node(tmp);
    	}
		printf("Tail node [%d] is next to be deleted.\n", stack->tail->num);
		delete_node(stack->tail);
	}
	if (stack->size == 1)
	{
		printf("Main node [%d] is next to be deleted", stack->head->num);
		delete_node(stack->head);
	}
	free(stack);
	printf("Stack has been deleted.\n");
}
