/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:45:11 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/16 17:08:34 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack **stack)
{
	t_stack	*cpy;
	int		min;

	cpy = *stack;
	min = cpy->number;
	while (cpy->next)
	{
		cpy = cpy->next;
		if (cpy->number < min)
			min = cpy->number;
	}
	return (min);
}

void	sort_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;
	int	min;
	
	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	min = get_min(stack_a);
	if (first == min && second > third)
		do_and_print(stack_a, NULL, 3, ra, sa, rra);
	else if (((first < third && first > second) || \
	(first > third && first < second)) && (second > third))
		do_and_print(stack_a, NULL, 1, rra);
	else if (((first < third && first > second) || \
	(first > third && first < second)) && (second < third))
			do_and_print(stack_a, NULL, 1, sa);
	else if (first > third && first > second && second < third)
		do_and_print(stack_a, NULL, 1, ra);
	else if (first > third && first > second && second > third)
		do_and_print(stack_a, NULL, 2, sa, rra);
}

static void	push_first(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		locate;
	t_stack	*cpy;

	locate = 1;
	min = get_min(stack_a);
	cpy = (*stack_a);
	while (cpy->number != min)
	{
		cpy = cpy->next;
		locate++;
	}
	if (locate == 1)
		do_and_print(stack_a, stack_b, 1, pb);
	else if (locate == 2)
		do_and_print(stack_a, stack_b, 2, sa, pb);
	else if (locate == 3)
		do_and_print(stack_a, stack_b, 3, ra, ra, pb);
	else if (locate == 4)
		do_and_print(stack_a, stack_b, 3, rra, rra, pb);
	else if (locate == 5)
		do_and_print(stack_a, stack_b, 2, rra, pb);
}

static void	push_second(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		locate;
	t_stack	*cpy;

	locate = 1;
	min = get_min(stack_a);
	cpy = (*stack_a);
	while (cpy->number != min)
	{
		cpy = cpy->next;
		locate++;
	}
	if (locate == 1)
		do_and_print(stack_a, stack_b, 1, pb);
	else if (locate == 2)
		do_and_print(stack_a, stack_b, 2, sa, pb);
	else if (locate == 3)
		do_and_print(stack_a, stack_b, 3, ra, ra, pb);
	else if (locate == 4)
		do_and_print(stack_a, stack_b, 2, rra, pb);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	push_first(stack_a, stack_b);
	push_second(stack_a, stack_b);
	sort_3(stack_a);
	do_and_print(stack_a, stack_b, 2, pa, pa);
}
