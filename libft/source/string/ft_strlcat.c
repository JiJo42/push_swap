/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:55:34 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:03:58 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = 0;
	if (size <= destlen)
		return (size + srclen);
	while (i < size - destlen - 1 && src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
