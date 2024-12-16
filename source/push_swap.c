/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:40:14 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/14 15:17:56 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b	= NULL;
	if (argc < 2)
		return (0);
	parsing_ps(argc, argv, &stack_a);
	stack_b = NULL;
	check_sort(&stack_a);
	sort_3(&stack_a);
	stackclear(&stack_a);
	stackclear(&stack_b);
}
