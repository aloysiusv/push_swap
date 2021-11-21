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

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define OK		0
# define NOT_OK -1
# define SORTED 1

typedef struct s_node
{
	int				value;
	int				index;
	int				moves;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	char	name;
	int		size;
	int		swap;
	int		rotate;
	int		reverse_rotate;
	int		ss;
	int		rr;
	int		rrr;
}				t_stack;

size_t	ft_strlen(const char *s);
int 	ft_is_digit(int c);
int		ft_atoi(const char *num_ascii);
long	ft_atol(const char *num_ascii);

int		is_input_valid(size_t nb_of_elements, char **input);
void	push_swap(t_stack *a, t_stack *b);

void	swap(t_stack *stack);
void	swap_both(t_stack *a, t_stack *b);
void	push(t_stack *pushing, t_stack *receiving);
void	rotate(t_stack *stack);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_both(t_stack *a, t_stack *b);

void	sort_5_and_less(t_stack *a, t_stack *b);
void	sort_500_and_less(t_stack *a, t_stack *b);

void	do_all_rot_equal(t_stack *a, t_stack *b);
void	do_rot_inferior(t_stack *a, t_stack *b);
void	do_rot_superior(t_stack *a, t_stack *b);
void	do_rev_rot_inferior(t_stack *a, t_stack *b);
void	do_rev_rot_superior(t_stack *a, t_stack *b);

void	stock_rotation_flags(t_stack *stack, int index);
void	push_group(t_stack *a, t_stack *b, int idx_min, int idx_max);
void    optimal_insertion_sort(t_stack *b, t_stack *a);

t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
int		is_new_min_max(t_stack *a, t_stack *b, int current_index);
void	put_min_top(t_stack *stack);
void	put_max_top(t_stack *stack);

t_node	*create_node(int num);
t_node	*add_bottom_node(t_node *current_node, int num);
void	delete_node(t_node *node);

int		init_stacks(t_stack *a, t_stack *b, int size, char **input);
void	delete_stacks(t_stack *a, t_stack *b);
int		find_pos(t_stack *stack, int index);
int		stack_sorted_at_this_pos(t_stack *stack);
int		stack_rev_sorted_at_this_pos(t_stack *stack);

#endif
