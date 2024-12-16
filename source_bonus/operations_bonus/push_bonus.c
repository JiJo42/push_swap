/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:22:30 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/14 18:22:14 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

/*Take the first element at the top of b and put it at the top of a*/
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
	{
		if (*stack_a)
		{
			(*stack_a)->previous = *stack_b;
			(*stack_b) = (*stack_b)->next;
			if (*stack_b)
				(*stack_b)->previous = NULL;
			(*stack_a)->previous->next = *stack_a;
			*stack_a = (*stack_a)->previous;
		}
		else
		{
			*stack_a = *stack_b;
			*stack_b = (*stack_b)->next;
			if (*stack_b)
				(*stack_b)->previous = NULL;
			(*stack_a)->next = NULL;	
		}
	}
}

/*Take the first element at the top of a and put it at the top of b*/
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
	{
		if (*stack_b)
		{
			(*stack_b)->previous = *stack_a;
			(*stack_a) = (*stack_a)->next;
			if (*stack_a)
				(*stack_a)->previous = NULL;
			(*stack_b)->previous->next = *stack_b;
			*stack_b = (*stack_b)->previous;
		}
		else
		{
			*stack_b = *stack_a;
			*stack_a = (*stack_a)->next;
			if (*stack_a)
				(*stack_a)->previous = NULL;
			(*stack_b)->next = NULL;			
		}
	}
}
