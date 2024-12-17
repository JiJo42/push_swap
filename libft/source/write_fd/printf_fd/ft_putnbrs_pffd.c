/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_pffd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:38:28 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/27 15:11:17 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printffd.h"

int	ft_putnbr_pffd(int fd, int nbr)
{
	int				i;
	unsigned int	number;

	i = 1;
	if (nbr < 0)
	{
		ft_putchar_pffd(fd, '-');
		number = nbr * -1;
		i++;
	}
	else
		number = nbr;
	if (number >= 10)
	{
		ft_putnbr_pffd(fd, number / 10);
		ft_putnbr_pffd(fd, number % 10);
	}
	else
		ft_putchar_pffd(fd, number + 48);
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned_pffd(int fd, unsigned int nbr)
{
	int	i;

	i = 1;
	if (nbr >= 10)
	{
		ft_putnbr_unsigned_pffd(fd, nbr / 10);
		ft_putnbr_unsigned_pffd(fd, nbr % 10);
	}
	else
		ft_putchar_pffd(fd, nbr + 48);
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
