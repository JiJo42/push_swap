/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pffd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:14:26 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/02 11:10:55 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printffd.h"

int	ft_putstr_pffd(int fd, const char *s)
{
	int	size;

	if (!s)
	{
		ft_putstr_pffd(fd, "(null)");
		return (6);
	}
	size = 0;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
		size++;
	}
	return (size);
}
