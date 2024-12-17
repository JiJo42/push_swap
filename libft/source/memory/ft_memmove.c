/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:00:57 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:02:58 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*from;
	char	*to;
	size_t	i;

	from = (char *)src;
	to = (char *)dest;
	if (from == to || n == 0)
		return (dest);
	if (to > from && to - from < (int)n)
	{
		i = n - 1;
		while (i > 0)
		{
			to[i] = from[i];
			i--;
		}
		to[i] = from[i];
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
