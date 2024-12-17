/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:26:12 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 14:40:21 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*find mediane and the 2 quartil of the stack*/
t_mq	*get_mq(t_stack **stack_a, int size)
{
	int		*tab;
	int 	i;
	t_stack	*cpy;
	t_mq	struc;
	t_mq	*data_mq;

	i = 0;
	data_mq = NULL;
	cpy = (*stack_a);
	tab = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		tab[i] = cpy->number;
		cpy = cpy->next;
		i++;
	}
	ft_insertion_sort(tab, size);
	struc.q1 = tab[size / 4];
	struc.med = tab[size / 2];
	struc.q3 = tab[(size / 4) * 3];
	data_mq = &struc;
	free(tab);
	return (data_mq);
}
