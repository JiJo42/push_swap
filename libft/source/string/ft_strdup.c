/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:11:56 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:03:48 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(src);
	dest = ft_calloc(size + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, size + 1);
	return (dest);
}
