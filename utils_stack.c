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

static int	fill_stack_bigger_than_two(size_t size, t_node **node, char **input)
{
	t_node	*tmp;
	size_t	i;

	i = 2;
	while (i < size)
	{
		tmp = add_bottom_node(*node, ft_atoi(input[i])); 
		if (tmp == NULL)
			return (-1);
		(*node)->next = tmp;
		tmp = tmp->next;
		*node = (*node)->next;
		i++;
	}
	return (0);
}

int	init_stacks(t_stack *a, t_stack *b, size_t nb_of_elements, char **input)
{
	t_node	*node;

	b->size = 0;
	b->head = NULL;
	b->tail = NULL;
	a->size = nb_of_elements;
	a->head = create_node(ft_atoi(input[0]));
	if (a->head == NULL)
		return (-1); 
	node = add_bottom_node(a->head, ft_atoi(input[1]));
	if (node == NULL)
		return (-1);
	a->head->prev = a->tail;
	a->head->next = node;
	if (a->size > 2)
		if (fill_stack_bigger_than_two(nb_of_elements, &node, input) == -1)
			return (-1);
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
		// t_node	*to_save;
	// t_node	*tmp;

	// if (stack->size == 1)
	// {
	// 	printf("Main node [%d] is next to be deleted\n", stack->head->num);
	// 	delete_node(stack->head);
	// 	stack->size--;
	// }
	// if (stack->size > 1)
	// {
	// 	to_save = stack->head;
	// 	while (to_save != stack->tail)
	// 	{
	//   		tmp = to_save;
    //   		to_save = to_save->next;
	//   		printf("Node [%d] is next to be deleted.\n", tmp->num);
	//   		delete_node(tmp);
	// 		stack->size--;
    // 	}
	// 	if (stack->tail != NULL)
	// 	{
	// 		printf("Tail node [%d] is next to be deleted.\n", stack->tail->num);
	// 		delete_node(stack->tail);
	// 		stack->size--;
	// 	}
	
	t_node	*tmp;

	while (stack->head != stack->tail)
	{
	  	tmp = stack->head;
      	stack->head = stack->head->next;
	  	delete_node(tmp);
		stack->size--;
	}
	if (stack->tail != NULL)
		delete_node(stack->tail);
	free(stack);
}