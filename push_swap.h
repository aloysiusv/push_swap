/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:29:05 by lrandria          #+#    #+#             */
/*   Updated: 2021/09/28 21:25:11 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define TRUE	0
# define FALSE	1

typedef struct s_node
{
	t_node	*prev;
	int	element;
	t_node	*next;
}				t_node;

typedef struct s_stack
{
	size_t	size;
	t_node	*start;
}				t_stack;

void	push_swap(t_stack *a, t_stack *b);

# endif