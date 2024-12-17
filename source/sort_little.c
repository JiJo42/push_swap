/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:45:11 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 09:48:31 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*find the smallest number of the stach and return it*/
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

/*find and push in b the smallest element of a stack of 5*/
static void	push_for_5(t_stack **stack_a, t_stack **stack_b)
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

/*find and push in b the smallest element of a stack of 4*/
static void	push_for_4(t_stack **stack_a, t_stack **stack_b)
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

/*sort a stack of 3 elements by checking all cases and
performing the adapt resolution solution*/
static void	sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;
	int	min;
	
	first = (*stack)->number;
	second = (*stack)->next->number;
	third = (*stack)->next->next->number;
	min = get_min(stack);
	if (first == min && second > third)
		do_and_print(stack, NULL, 2, rra, sa);
	else if (((first < third && first > second) || \
	(first > third && first < second)) && (second > third))
		do_and_print(stack, NULL, 1, rra);
	else if (((first < third && first > second) || \
	(first > third && first < second)) && (second < third))
			do_and_print(stack, NULL, 1, sa);
	else if (first > third && first > second && second < third)
		do_and_print(stack, NULL, 1, ra);
	else if (first > third && first > second && second > third)
		do_and_print(stack, NULL, 2, sa, rra);
}

/*sort a stack with size of maximum 5 element:
- stack of 2 by rotating
- stack of 3 by checking all cases and performing the adapt resolution solution
- stack of 4 or 5 element by pushing the smallest (1 or 2) in b and sort the 3 
	last with same method like a stack of 3 before return the smallest in a*/
void	sort_little(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		do_and_print(stack_a, stack_b, 1, sa);
	else if (size == 3)
		sort_3(stack_a);
	else
	{
		if (size == 5)
			push_for_5(stack_a, stack_b);
		push_for_4(stack_a, stack_b);
		sort_3(stack_a);
		if (size == 4)
			do_and_print(stack_a, stack_b, 1, pa);
		else
			do_and_print(stack_a, stack_b, 2, pa, pa);
	}
}
