/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:07:28 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 16:03:08 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	search_and_do_3(t_stack **stack_a, t_stack **stack_b, int code)
{
	if (code == RRA)
	{
		reverse_rotate_a(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (code == RRB)
	{
		reverse_rotate_b(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (code == RRR)
	{
		reverse_rotate_both(stack_a, stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}

static void	search_and_do_2(t_stack **stack_a, t_stack **stack_b, int code)
{
	if (code == PB)
	{
		push_b(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
	}
	else if (code == RA)
	{
		rotate_a(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (code == RB)
	{
		rotate_b(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (code == RR)
	{
		rotate_both(stack_a, stack_b);
		ft_putstr_fd("rr\n", 1);
	}
	else
		search_and_do_3(stack_a, stack_b, code);
}

static void	search_and_do(t_stack **stack_a, t_stack **stack_b, int code)
{
	if (code == SA)
	{
		swap_a(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (code == SB)
	{
		swap_b(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (code == SS)
	{
		swap_both(stack_a, stack_b);
		ft_putstr_fd("ss\n", 1);
	}
	else if (code == SA)
	{
		push_a(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
	}
	else
		search_and_do_2(stack_a, stack_b, code);
}

void	do_and_print(t_stack **stack_a, t_stack **stack_b, int size, ...)
{
	va_list	codes;
	int		code;

	va_start(codes, size);
	while (size)
	{
		code = va_arg(codes, int);
		search_and_do(stack_a, stack_b, code);
		size--;
	}
	va_end(codes);
}
