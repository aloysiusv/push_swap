/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:15:34 by lrandria          #+#    #+#             */
/*   Updated: 2021/11/23 09:55:27 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	do_operations(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(b);
	else if (ft_strcmp(line, "ss") == 0)
		swap_both(a, b);
	else if (ft_strcmp(line, "pa") == 0)
		push(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		push(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_both(a, b);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_both(a, b);
	else
		return (-1);
	return (0);
}

int	checker(t_stack *a, t_stack *b)
{
	char	*operations;
	int		ret;

	ret = get_next_line(0, &operations);
	while (ret > 0)
	{
		if (do_operations(a, b, operations) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		ret = get_next_line(0, &operations);
	}
	if (ret == -1)
		return (-1);
	if (b->head == NULL && stack_sorted_at_this_pos(a) == a->size - 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ret;

	if (argc == 1)
		return (0);
	if (is_input_valid(argc - 1, argv + 1) == NOT_OK)
	{	
		write(2, "Error\n", 6);
		return (255);
	}
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (a == NULL || b == NULL)
		return (delete_stacks(a, b));
	if (init_stacks(a, b, argc - 1, argv + 1) == SORTED)
	{
		write(1, "OK\n", 3);
		return (delete_stacks(a, b));
	}
	ret = checker(a, b);
	delete_stacks(a, b);
	if (ret == -1)
		return (255);
	return (0);
}
