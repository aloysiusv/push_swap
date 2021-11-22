/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_double_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/22 18:30:16 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rot_inferior(t_stack *a, t_stack *b)
{
	if (b->rotate < a->rotate)
	{
		a->rr++;
		b->rr++;
		while (b->rotate)
		{
			rotate_both(a, b);
			b->rotate--;
			a->rotate--;
		}
		a->rr = 0;
		b->rr = 0;
		while (a->rotate)
		{
			rotate(a);
			a->rotate--;
		}
	}
}

void	do_rot_superior(t_stack *a, t_stack *b)
{
	if (b->rotate > a->rotate)
	{
		a->rr++;
		b->rr++;
		while (a->rotate)
		{
			rotate_both(a, b);
			b->rotate--;
			a->rotate--;
		}
		a->rr = 0;
		b->rr = 0;
		while (b->rotate)
		{
			rotate(b);
			b->rotate--;
		}
	}
}

void	do_rev_rot_inferior(t_stack *a, t_stack *b)
{
	if (b->reverse_rotate < a->reverse_rotate)
	{
		a->rrr++;
		b->rrr++;
		while (b->reverse_rotate)
		{
			reverse_rotate_both(a, b);
			b->reverse_rotate--;
			a->reverse_rotate--;
		}
		a->rrr = 0;
		b->rrr = 0;
		while (a->reverse_rotate)
		{
			reverse_rotate(a);
			a->reverse_rotate--;
		}
	}
}

void	do_rev_rot_superior(t_stack *a, t_stack *b)
{
	if (b->reverse_rotate > a->reverse_rotate)
	{
		a->rrr++;
		b->rrr++;
		while (a->reverse_rotate)
		{
			reverse_rotate_both(a, b);
			b->reverse_rotate--;
			a->reverse_rotate--;
		}
		a->rrr = 0;
		b->rrr = 0;
		while (b->reverse_rotate)
		{
			reverse_rotate(b);
			b->reverse_rotate--;
		}
	}
}
