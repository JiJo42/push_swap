/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:45:11 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/13 14:53:57 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->number;
	while (head->next)
	{
		head = head->next;
		if ((head->number < min) && head->number != val)
			min = head->number;
	}
	return (min);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (head->number == min && head->next->number != next_min)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
		ft_printf("%s%s%s", ra, sa, rra);
	}
	else if (head->number == next_min)
	{
		if (head->next->number == min)
		{
			swap_a(stack_a);
			ft_printf("%s", sa);
		}
		else
		{
			reverse_rotate_a(stack_a);
			ft_printf("%s", rra);
		}
	}
	else
	{
		if (head->next->number == min)
		{
			rotate_a(stack_a);
			ft_printf("%s", ra);
		}
		else
		{
			swap_a(stack_a);
			reverse_rotate_a(stack_a);
			ft_printf("%s%s", sa, rra);
		}
	}
}
