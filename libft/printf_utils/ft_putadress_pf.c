/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:02:12 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/29 14:17:27 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_rev_pf(const char *s)
{
	int	size;

	size = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s--;
		size++;
	}
	return (size);
}

int	ft_putadress_pf(unsigned long int nbr, char *base)
{
	int		i;
	char	str[17];

	if (nbr == 0)
	{
		ft_putstr_pf("(nil)");
		return (5);
	}
	i = 0;
	while (nbr > 0)
	{
		str[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	str[16] = '\0';
	return (ft_putstr_pf("0x") + ft_putstr_rev_pf(str + i - 1));
}
