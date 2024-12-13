/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:55:43 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/13 15:48:58 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check if the argument are in ASCII range of an interger (>0,9<,+,-,' ')
exit if not*/
static void	isvalid(char *str, t_stack **stack_a)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9')
			&& (*str != ' ' && *str != '+' && *str != '-'))
			parsing_exit(stack_a, NULL, ERROR);
		str++;
	}
}

/*split the argument for checking how many interger are in.
Exit if error (memory or 0 interger)*/
static char	**split_arg(char *arg, t_stack **stack_a)
{
	char	*trim;
	char	**split;
	
	trim = ft_strtrim(arg, " ");
	if (!trim)
		parsing_exit(stack_a, NULL, MEMORY_ERROR);
	if (!*trim)
	{
		free(trim);
		parsing_exit(stack_a, NULL, ERROR);
	}
	split = ft_split(trim, ' ');
	free(trim);
	if (!split)
		parsing_exit(stack_a, NULL, MEMORY_ERROR);
	return (split);
}

/*Check if the interger contain in the split result are valid and the right 
size (no double signe, int size) and add the interger to the stack.
Exit if an interger are invalid*/
static void	check_and_add_split(char **split, t_stack **stack_a)
{
	int		atoi;
	long	atol;
	int		index;
	t_stack	*new;

	index = 0;
	while (split[index])
	{
		atoi = atoi_ps(split[index]);
		atol = ft_atol(split[index]);
		if (atoi == ERROR || atoi != atol)
			parsing_exit(stack_a, split, ERROR);
		new = stacknew(atoi);
		if (!new)
			parsing_exit(stack_a, split, MEMORY_ERROR);
		stackadd(stack_a, new);
		index++;
	}
}
/*Check if any inerger of the stack existe in one copy
if it is not the case exit*/
static void	check_double(t_stack *stack_a)
{
	t_stack	*be_check;
	t_stack	*check_by;
	 //a reparer (double while + faire un check de deja trier)
	be_check = stack_a;
	while (be_check->next)
	{
		check_by = be_check->next;
		if (be_check->number == check_by->number)
			parsing_exit(&stack_a, NULL, ERROR);
		be_check = be_check->next;
	}
}

/*check if all the arguments are available for the program
(are a valid interger and no double) and if the stack are already sort
return the created stack_a if not exit(unavailable or already sort)*/
void	parsing_ps(int argc, char **argv, t_stack **stack_a)
{
	char	**split;
	int		index;

	index = 1;
	while (index < argc)
	{ 
		isvalid(argv[index], stack_a);
		split = split_arg(argv[index], stack_a);
		check_and_add_split(split, stack_a);
		freetab(split);
		index++;
	}
	check_double(*stack_a);
}
