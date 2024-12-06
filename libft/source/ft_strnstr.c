/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:15:18 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/25 10:12:48 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (str == NULL || len == 0)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while ((to_find[i2] != '\0') && (str[i + i2] == to_find[i2]))
		{
			if (str[i + i2] == '\0' || (i + i2) >= len)
				return (NULL);
			i2++;
		}
		if (to_find[i2] == '\0')
			return ((char *)&str[i]);
		else
			i2 = 0;
		i++;
	}
	return (NULL);
}
