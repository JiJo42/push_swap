/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:40:14 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 11:29:52 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		size;
	
	stack_a = NULL;
	stack_b	= NULL;
	if (argc < 2)
		return (0);
	parsing_ps(argc, argv, &stack_a);
	stack_b = NULL;
	check_sort(&stack_a);
	size = stacksize(stack_a);
	if (size <= 5)
		sort_little(&stack_a, &stack_b, size);
	else
		sort_big(&stack_a, &stack_b, size);
	stackclear(&stack_a);
	stackclear(&stack_b);
}
