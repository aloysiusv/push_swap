/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/01 19:15:34 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_three(t_stack *stack)
{
	if (stack->size == 2)
		if (stack->head->num > stack->head->next->num)
			swap(stack, 'a');
	if (stack->size == 3)
	{
		
	}

}

void	sort_5_and_less(t_stack *a, t_stack *b)
{

}

void	sort_100_and_less(t_stack *a, t_stack *b)
{

}

void	sort_500_and_less(t_stack *a, t_stack *b)
{

}
