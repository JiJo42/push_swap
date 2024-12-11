/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:21:55 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/11 08:20:51 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*Swap the first 2 elements at the top of stack a*/
void	swap_a(t_stack **stack_a)
{
	t_stack	*second;
	t_stack	*first;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
}

/*Swap the first 2 elements at the top of stack b*/
void	swap_b(t_stack **stack_b)
{
	t_stack	*second;
	t_stack	*first;

	first = *stack_b;
	second = first->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
}

/*Swap the first 2 elements at the top of stack a and stack b*/
void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
