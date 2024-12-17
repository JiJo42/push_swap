/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:00:21 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:03:16 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_insertion_sort(int *tab, int size)
{
	int	index;
	int	location;
	int	copy;

	index = 1;
	while (index < size)
	{
		copy = tab[index];
		location = index;
		while (location && (tab[location - 1] > copy))
		{
			tab[location] = tab[location - 1];
			location--;
		}
		tab[location] = copy;
		index++;
	}
}
