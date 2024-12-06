/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:55:43 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/06 08:05:29 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parsing(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**split;
	int		index;
	
	stack_a = NULL;
	index = 1;
	while(index < argc - 1)
	{
		isvalide(argv[index]);
		split = ft_split(argv[index], ' ');
		if (split == NULL)
		{
			ft_stackclear(&stack_a);
			ps_exit(MEMORY_ERROR);
		}
		
	}
}
