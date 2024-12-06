/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:14:26 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/15 19:58:57 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(const char *s)
{
	int	size;

	if (!s)
	{
		ft_putstr_pf("(null)");
		return (6);
	}
	size = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		size++;
	}
	return (size);
}

void	ft_putstr_error(const char *s)
{
	while (*s != '\0')
	{
		write(2, s, 1);
		s++;
	}
}
