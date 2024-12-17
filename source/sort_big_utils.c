/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:26:12 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:59:46 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*find mediane and the 2 quartil of the stack*/
void	get_mq(t_stack **stack_a, int size, t_mq *data_mp)
{
	int		*tab;
	int		i;
	t_stack	*cpy;

	i = 0;
	cpy = (*stack_a);
	tab = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		tab[i] = cpy->number;
		cpy = cpy->next;
		i++;
	}
	ft_insertion_sort(tab, size);
	data_mp->q1 = tab[size / 4];
	data_mp->med = tab[size / 2];
	data_mp->q3 = tab[(size / 4) * 3];
	free(tab);
}
