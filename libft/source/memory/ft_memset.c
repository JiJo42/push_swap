/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:52:34 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:03:03 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*s_cpy;
	unsigned char	c_cpy;

	s_cpy = s;
	c_cpy = c;
	while (n > 0)
	{
		*s_cpy = c_cpy;
		s_cpy++;
		n--;
	}
	return (s);
}
