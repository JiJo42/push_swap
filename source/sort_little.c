/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:45:11 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/16 16:11:46 by dleclerc         ###   ########.fr       */
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

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (head->number == min && head->next->number != next_min)
		do_and_print(stack_a, NULL, 3, ra, sa, rra);
	else if (head->number == next_min)
	{
		if (head->next->number == min)
			do_and_print(stack_a, NULL, 1, sa);
		else
			do_and_print(stack_a, NULL, 1, rra);
	}
	else
	{
		if (head->next->number == min)
			do_and_print(stack_a, NULL, 1, ra);
		else
			do_and_print(stack_a, NULL, 2, sa, rra);
	}
}
