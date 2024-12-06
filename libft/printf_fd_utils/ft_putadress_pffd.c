/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_pffd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:02:12 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/27 15:09:59 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printffd.h"

static int	ft_putstr_rev_pffd(int fd, const char *s)
{
	int	size;

	size = 0;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s--;
		size++;
	}
	return (size);
}

int	ft_putadress_pffd(int fd, unsigned long int nbr, char *base)
{
	int		i;
	char	str[17];

	if (nbr == 0)
	{
		ft_putstr_pffd(fd, "(nil)");
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
	return (ft_putstr_pffd(fd, "0x") + ft_putstr_rev_pffd(fd, str + i - 1));
}
