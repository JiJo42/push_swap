/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:07:28 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/14 15:16:10 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	search_and_do_3(t_stack **stack_a, t_stack **stack_b, int code)
{
	if (code == rra)
	{
		reverse_rotate_a(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (code == rrb)
	{
		reverse_rotate_b(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (code == rrr)
	{
		reverse_rotate_both(stack_a, stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}

static void	search_and_do_2(t_stack **stack_a, t_stack **stack_b, int code)
{
	if (code == pb)
	{
		push_b(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
	}
	else if (code == ra)
	{
		rotate_a(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (code == rb)
	{
		rotate_b(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (code == rr)
	{
		rotate_both(stack_a, stack_b);
		ft_putstr_fd("rr\n", 1);
	}
	else
		search_and_do_3(stack_a, stack_b, code);
}

static void	search_and_do(t_stack **stack_a, t_stack **stack_b, int code)
{
	if (code == sa)
	{
		swap_a(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (code == sb)
	{
		swap_b(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (code == ss)
	{
		swap_both(stack_a, stack_b);
		ft_putstr_fd("ss\n", 1);
	}
	else if (code == pa)
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
	int code;
	
	va_start(codes, size);
	while (size)
	{
		code = va_arg(codes, int);
		search_and_do(stack_a, stack_b, code);
		size--;
	}
	va_end(codes);
}
