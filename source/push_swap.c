/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:40:14 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/12 11:19:40 by dleclerc         ###   ########.fr       */
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

	t_stack *tmp_a = stack_a;
	t_stack *tmp_b = stack_b;
	
	if (stack_a)
	{
		ft_printf("stack a\n");
		while (tmp_a)
		{
			ft_printf("%d\n", tmp_a->number);
			tmp_a = tmp_a->next;
		}
		ft_printf("stack a reverse\n");
		tmp_a = stack_a;
		while (tmp_a->next)
			tmp_a = tmp_a->next;
		while (tmp_a)
		{
			ft_printf("%d\n", tmp_a->number);
			tmp_a = tmp_a->previous;
		}
	}
	
	ft_printf("\npush\n\n");
	push_b (&stack_a, &stack_b);
	push_b (&stack_a, &stack_b);
	push_b (&stack_a, &stack_b);

	if (stack_b)
	{
		tmp_b = stack_b;
		ft_printf("stack b\n");
		while (tmp_b)
		{
			ft_printf("%d\n", tmp_b->number);
			tmp_b = tmp_b->next;
		}
		ft_printf("stack b reverse\n");
		tmp_b = stack_b;
		while (tmp_b->next)
			tmp_b = tmp_b->next;
		while (tmp_b)
		{
			ft_printf("%d\n", tmp_b->number);
			tmp_b = tmp_b->previous;
		}
	}

	if (stack_a)
	{
		tmp_a = stack_a;
		ft_printf("stack a\n");
		while (tmp_a)
		{
			ft_printf("%d\n", tmp_a->number);
			tmp_a = tmp_a->next;
		}
		ft_printf("stack a reverse\n");
		tmp_a = stack_a;
		while (tmp_a->next)
			tmp_a = tmp_a->next;
		while (tmp_a)
		{
			ft_printf("%d\n", tmp_a->number);
			tmp_a = tmp_a->previous;
		}
	}

	ft_printf("\nswap\n\n");
	swap_a(&stack_a);
	swap_b(&stack_b);
	
	if (stack_a)
	{
		tmp_a = stack_a;
		ft_printf("stack a\n");
		while (tmp_a)
		{
			ft_printf("%d\n", tmp_a->number);
			tmp_a = tmp_a->next;
		}
		ft_printf("stack a reverse\n");
		tmp_a = stack_a;
		while (tmp_a->next)
			tmp_a = tmp_a->next;
		while (tmp_a)
		{
			ft_printf("%d\n", tmp_a->number);
			tmp_a = tmp_a->previous;
		}
	}


	if (stack_b)
	{
		tmp_b = stack_b;
		ft_printf("stack b\n");
		while (tmp_b)
		{
			ft_printf("%d\n", tmp_b->number);
			tmp_b = tmp_b->next;
		}
		ft_printf("stack b reverse\n");
		tmp_b = stack_b;
		while (tmp_b->next)
			tmp_b = tmp_b->next;
		while (tmp_b)
		{
			ft_printf("%d\n", tmp_b->number);
			tmp_b = tmp_b->previous;
		}
	}

	
	stackclear(&stack_a);
	stackclear(&stack_b); //here for security remove before push
}
