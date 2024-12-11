/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:22:30 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/11 08:21:55 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*Take the first element at the top of b and put it at the top of a*/
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a)->previous = *stack_b;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->previous = NULL;
}

/*Take the first element at the top of a and put it at the top of b*/
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_b)->previous = *stack_a;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
}