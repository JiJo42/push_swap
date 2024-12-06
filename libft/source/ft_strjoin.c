/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:16:57 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/18 10:05:32 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = ft_calloc(s1len + s2len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1len + 1);
	ft_strlcat(str, s2, s1len + s2len + 1);
	return (str);
}
