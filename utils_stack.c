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

void	fill_stack(t_stack *stack, size_t nb_of_elements, char **input)
{
	t_node	*node;
	t_node	*tmp;
	size_t	i;

	i = 0;
	stack->size = nb_of_elements;
	stack->head = create_node(ft_atoi(input[i]));
	i = 1;
	node = add_bottom_node(stack->head, ft_atoi(input[i]));
	stack->head->prev = stack->head;
	stack->head->next = node;
	while (++i < nb_of_elements)
	{
		tmp = add_bottom_node(node, ft_atoi(input[i])); 
		node->next = tmp;
		tmp = tmp->next;
		node = node->next;
	}
	stack->tail = node;
	stack->tail->next = stack->head;
	if (stack->head == NULL || node == NULL || tmp == NULL)
		return ;
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

// void	delete_stack(t_stack *stack)
// {
// 	t_node	*current;
// 	t_node	*tmp;
//
// 	current = stack->head->next;
// 	while (current != stack->head)
// 	{
// 	  tmp = current;
//       current = current->next;
// 	  printf("Node [%d] is next to be deleted.\n", tmp->num);
// 	  delete_node(tmp);
//     }
// 	printf("Head node [%d] is next to be deleted.\n", stack->head->num);
// 	delete_node(stack->head);
// 	free(stack);
// 	printf("Stack has been deleted.\n");
// }

void	delete_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

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
	free(stack);
	printf("Stack has been deleted.\n");
}
