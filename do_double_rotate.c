/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_double_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:27:20 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/22 19:00:36 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate_both(t_stack *a, t_stack *b)
{
	if (b->rotate == a->rotate)
	{
		a->rr++;
		b->rr++;
		while (b->rotate && a->rotate)
		{
			rotate_both(a, b);
			b->rotate--;
			a->rotate--;
		}
		a->rr = 0;
		b->rr = 0;
	}
}

static void	do_reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (b->reverse_rotate == a->reverse_rotate)
	{
		a->rrr++;
		b->rrr++;
		while (b->reverse_rotate && a->reverse_rotate)
		{
			reverse_rotate_both(a, b);
			b->reverse_rotate--;
			a->reverse_rotate--;
		}
		a->rrr = 0;
		b->rrr = 0;
	}
}

void	do_all_rot_equal(t_stack *a, t_stack *b)
{
	do_rotate_both(a, b);
	do_reverse_rotate_both(a, b);
}
