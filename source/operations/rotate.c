/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:48:29 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/13 08:23:28 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*Shift up all elements of stack a by 1*/
void	rotate_a(t_stack **stack_a)
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
			*stack_a = first->next; 
			first->next->previous = NULL;
			first->next = NULL;
			last->next = first;
			first->previous = last;
		}
	}
}

/*Shift up all elements of stack b by 1*/
void	rotate_b(t_stack **stack_b)
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
			*stack_b = first->next; 
			first->next->previous = NULL;
			first->next = NULL;
			last->next = first;
			first->previous = last;
		}
	}
}


/*Shift up all elements of stack a and stack b by 1*/
void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}