/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:08:08 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 16:00:51 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*Shift down all elements of stack a by 1*/
void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_a)
	{
		if (stacksize(*stack_a) < 3)
			swap_a(stack_a);
		else
		{
			first = *stack_a;
			last = first;
			while (last->next)
				last = last->next;
			last->previous->next = NULL;
			last->previous = NULL;
			first->previous = last;
			last->next = first;
			*stack_a = last;
		}
	}
}

/*Shift down all elements of stack b by 1*/
void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_b)
	{
		if (stacksize(*stack_b) < 3)
			swap_b(stack_b);
		else
		{
			first = *stack_b;
			last = first;
			while (last->next)
				last = last->next;
			last->previous->next = NULL;
			last->previous = NULL;
			first->previous = last;
			last->next = first;
			*stack_b = last;
		}
	}
}

/*Shift down all elements of stack a and stack b by 1*/
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
