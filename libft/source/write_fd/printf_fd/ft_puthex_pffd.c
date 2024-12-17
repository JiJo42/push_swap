/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pffd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:17:00 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/27 15:10:38 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printffd.h"

int	ft_puthex_pffd(int fd, unsigned int nbr, char *base)
{
	int	i;

	i = 1;
	if (nbr >= 16)
	{
		ft_puthex_pffd(fd, nbr / 16, base);
		ft_puthex_pffd(fd, nbr % 16, base);
	}
	else
		ft_putchar_pffd(fd, base[nbr]);
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}
