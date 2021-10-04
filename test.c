/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:03:18 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 22:03:18 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->num = num;
	node->prev = node;
	node->next = node;
	printf("Node has been created.\n");
	return (node);
}

t_node	*add_top_node(t_node *current_node, int num)
{
	t_node	*top;

	top = create_node(num);
	if (top == NULL)
		return (0);
	if (current_node)
	{
		top->prev = top;
		top->next = current_node;
	}
	else
		current_node = top;
	printf("Top node [%d] added.\n", top->num);
	return(top);
}

t_node	*add_bottom_node(t_node *current_node, int num)
{
	t_node	*bottom;

	bottom = create_node(num);
	if (bottom == NULL)
		return (0);
	if (current_node)
	{
		bottom->prev = current_node;
		bottom->next = current_node;
	}
	else
		current_node = bottom;
	printf("Bottom node [%d] added.\n", bottom->num);
	return(bottom);
}

void	delete_node(t_node *node)
{
	if (node == 0)
		return ;
	free(node);
}

t_stack	*create_stack(size_t nb_of_elements, int *tab)
{
	t_stack	*stack;
	t_node	*node;
	t_node	*tmp;
	size_t	i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (0);
	i = 0;
	stack->size = nb_of_elements;
	stack->head = create_node(tab[i]);
	if (stack->head != NULL)
		printf("Head node [%d] initialised.\n", stack->head->num);
	i = 1;
	node = add_bottom_node(stack->head, tab[i]);
	if (node == NULL)
		return (0);
	stack->head->prev = stack->head;
	stack->head->next = node;
	while (++i < nb_of_elements)
	{
		tmp = add_bottom_node(node, tab[i]); 
		node->next = tmp;
		tmp = tmp->next;
		node = node->next;
	}
	stack->tail = node;
	stack->tail->next = stack->head;
	if (stack->tail != NULL)
		printf("Tail node [%d] initialised.\n", stack->tail->num);
	printf("Stack has been created.\n");
	return (stack);
}

void	delete_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack->head->next;
	while (current != stack->head)
	{
	  tmp = current;
      current = current->next;
	  printf("Node [%d] is next to be deleted.\n", tmp->num);
      delete_node(tmp);
      
    }
	printf("Head node [%d] is next to be deleted.\n", stack->head->num);
	delete_node(stack->head);
	free(stack);
	printf("Stack has been deleted.\n");
}

int	main(int argc, char **argv)
{
	size_t nb_of_elements = 3;
	int tab[] = {293, 23, 54};
	t_stack *stack_a;

	stack_a = create_stack(nb_of_elements, tab);
	swap(stack_a);
	delete_stack(stack_a);
	return (0);
}
