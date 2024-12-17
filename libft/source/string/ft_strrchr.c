/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:18:03 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:04:23 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	c = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	if (j != -1)
		return ((char *)&s[j]);
	return (NULL);
}
