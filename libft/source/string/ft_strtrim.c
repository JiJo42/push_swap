/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:11:34 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:04:26 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			return (len - i);
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	size = end - start;
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, size + 1);
	return (str);
}
