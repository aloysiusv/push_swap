/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:27:05 by lrandria          #+#    #+#             */
/*   Updated: 2021/10/01 21:27:05 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define MIN 0
# define MAX 1

typedef enum e_bool
{
	NOT_OK,
	OK
}			t_bool;

typedef struct s_node
{
	int				touched;
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	int		size;
	size_t	count_op;
	t_node	*head;
}				t_stack;

size_t	ft_strlen(const char *s);
int 	ft_is_digit(int c);
int		ft_atoi(const char *num_ascii);
long	ft_atol(const char *num_ascii);

t_bool	is_input_valid(size_t nb_of_elements, char **input);
void	push_swap(t_stack *a, t_stack *b);

void	swap(t_stack *stack, char name);
void	swap_both(t_stack *a, t_stack *b);
void	push(t_stack *pushing, t_stack *receiving, char name);
void	rotate(t_stack *stack, char name);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack, char name);
void	reverse_rotate_both(t_stack *a, t_stack *b);

void	sort_3(t_stack *a);
void	sort_5_and_less(t_stack *a, t_stack *b);
void	sort_100_and_less(t_stack *a, t_stack *b);
void	sort_500_and_less(t_stack *a, t_stack *b);

int     find_min(t_stack *stack);
int     find_max(t_stack *stack);
int		find_min_pos(t_stack *stack);
int		find_max_pos(t_stack *stack);
void	put_min_top(t_stack *stack, char name);
void	put_max_top(t_stack *stack, char name);

t_node	*create_node(int num);
t_node	*add_bottom_node(t_node *current_node, int num);
void	delete_node(t_node *node);

int		init_stacks(t_stack *a, t_stack *b, size_t size, char **input);
void	delete_stack(t_stack *stack);
int		is_stack_sorted(t_stack *stack);

#endif
