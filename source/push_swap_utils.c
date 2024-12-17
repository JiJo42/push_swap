/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:40:14 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:51:11 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*clear a **string*/
void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*check if stack are already sort, exit if yes*/
void	check_sort(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = first->next;
	while (second && first->number < second->number)
	{
		first = first->next;
		second = second->next;
	}
	if (!second)
		ps_exit(stack_a, NULL, NO_ERROR);
	else
		return ;
}

/*sort clean and put error message*/
void	ps_exit(t_stack **stack_a, t_stack **stack_b, int code)
{
	stackclear(stack_a);
	stackclear(stack_b);
	if (code == ERROR)
		ft_putstr_fd("Error\n", 2);
	else if (code == MEMORY_ERROR)
		ft_putstr_fd("Memory Error\n", 2);
	exit(EXIT_FAILURE);
}
