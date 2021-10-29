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
	node->value = num;
	node->index = -1;
	node->prev = node;
	node->next = node;
	printf("A node has been created.\n");
	return (node);
}

t_node	*add_bottom_node(t_node *current_tail, int num)
{
	t_node	*bottom;

	bottom = create_node(num);
	if (bottom == NULL)
		return (0);
	if (current_tail)
	{
		bottom->prev = current_tail;
		bottom->next = current_tail->prev;
		current_tail->next = bottom;
	}
	else
		current_tail = bottom;
	return(bottom);
}

void	delete_node(t_node *node)
{
	if (node == NULL)
		return ;
	free(node);
}
