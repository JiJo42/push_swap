/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:52:29 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:03:38 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*fill_nbr(long int nbr, char *str, int i)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr > 9)
	{
		fill_nbr(nbr / 10, str, i - 1);
		fill_nbr(nbr % 10, str, i);
	}
	else
		(str[i] = nbr + 48);
	return (str);
}

static int	count_i(long int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = count_i(n);
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str = fill_nbr(n, str, size - 1);
	return (str);
}
