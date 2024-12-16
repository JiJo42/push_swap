/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:40:14 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/16 13:26:42 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

/*check if the stack is sort (check before (code = 1) and after (code =2))
Exit if not*/
void	check_sort(t_stack **stack_a, t_stack **stack_b, int code)
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
	if (code == 1 && (!second))
		checker_exit(stack_a, stack_b, OK);
	else if (code == 2 && second)
		checker_exit(stack_a, stack_b, KO);
	else
		return ;
}

/*exit clear and put message*/
void	checker_exit(t_stack **stack_a, t_stack **stack_b, int code)
{
	if (stack_a)
		stackclear(stack_a);
	if (stack_b)
		stackclear(stack_b);
	if (code != OK)
	{
		if (code == ERROR)
			ft_putstr_fd("Error\n", 2);
		else if (code == MEMORY_ERROR)
			ft_putstr_fd("Memory Error\n", 2);
		else if (code == KO)
			ft_putstr_fd("KO\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("OK\n", 2);
		exit(EXIT_SUCCESS);
	}
}
