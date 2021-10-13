/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:42:05 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/04 21:42:05 by lrandria         ###   ########.fr       */
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
	printf("A node has been created.\n");
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
		current_node->prev = top;
	}
	else
		current_node = top;
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
		current_node->next = bottom;
	}
	else
		current_node = bottom;
	return(bottom);
}

void	delete_node(t_node *node)
{
	if (node == 0)
		return ;
	free(node);
}
