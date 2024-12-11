/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:17:00 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/15 19:58:53 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int nbr, char *base)
{
	int	i;

	i = 1;
	if (nbr >= 16)
	{
		ft_puthex_pf(nbr / 16, base);
		ft_puthex_pf(nbr % 16, base);
	}
	else
		ft_putchar_pf(base[nbr]);
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}
