/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:21:55 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/10 10:12:56 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}