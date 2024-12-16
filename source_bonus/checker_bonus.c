/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:00:46 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/16 11:32:01 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b	= NULL;
	if (argc < 2)
		return (0);
	parsing_ck(argc, argv, &stack_a);
	stack_b = NULL;
	check_sort(&stack_a, &stack_b, 1);
	get_stdin(&stack_a, &stack_b);
	check_sort(&stack_a, &stack_b, 2);
	checker_exit(&stack_a, &stack_b, OK);
}
