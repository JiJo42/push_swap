/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:21:55 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/16 11:10:42 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

/*Swap the first 2 elements at the top of stack a*/
void	swap_a(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		(*stack_a)->previous = (*stack_a)->next;
		if ((*stack_a)->next->next)
		{
			(*stack_a)->next = (*stack_a)->next->next;
			(*stack_a)->next->previous = *stack_a;
		}
		else
			(*stack_a)->next = NULL;
		(*stack_a)->previous->previous = NULL;
		(*stack_a)->previous->next = *stack_a;
		*stack_a = (*stack_a)->previous;	
	}
}

/*Swap the first 2 elements at the top of stack b*/
void	swap_b(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		(*stack_b)->previous = (*stack_b)->next;
		if ((*stack_b)->next->next)
		{
			(*stack_b)->next = (*stack_b)->next->next;
			(*stack_b)->next->previous = *stack_b;
		}
		else
			(*stack_b)->next = NULL;
		(*stack_b)->previous->previous = NULL;
		(*stack_b)->previous->next = *stack_b;
		*stack_b = (*stack_b)->previous;	
	}
}

/*Swap the first 2 elements at the top of stack a and stack b*/
void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
