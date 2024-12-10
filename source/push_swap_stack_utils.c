/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:40:14 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/10 10:46:37 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*create and return a new stack element*/
t_stack	*ft_stacknew(int content)
{
	t_stack	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->number = content;
	element->next = NULL;
	element->previous = NULL;
	return (element);
}

/*add an element to the stack*/
void	ft_stackadd(t_stack **stack, t_stack *new)
{
	t_stack	*last;

		last = ft_stacklast(*stack);
		if (!last)
			*stack = new;
		else
		{
			last->next = new;
			new->previous = last;
		}
}

/*find and return the last element of a stack*/
t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*clear the stack*/
void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
		stack = NULL;
	}
}
