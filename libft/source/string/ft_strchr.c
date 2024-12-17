/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:18:03 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:03:44 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
