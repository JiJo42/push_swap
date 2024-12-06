/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:38:28 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/15 19:58:54 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int nbr)
{
	int				i;
	unsigned int	number;

	i = 1;
	if (nbr < 0)
	{
		ft_putchar_pf('-');
		number = nbr * -1;
		i++;
	}
	else
		number = nbr;
	if (number >= 10)
	{
		ft_putnbr_pf(number / 10);
		ft_putnbr_pf(number % 10);
	}
	else
		ft_putchar_pf(number + 48);
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned_pf(unsigned int nbr)
{
	int	i;

	i = 1;
	if (nbr >= 10)
	{
		ft_putnbr_unsigned_pf(nbr / 10);
		ft_putnbr_unsigned_pf(nbr % 10);
	}
	else
		ft_putchar_pf(nbr + 48);
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
