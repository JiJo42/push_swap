/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:16:35 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:03:41 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_words(const char *s, char c)
{
	int	b;
	int	wc;

	b = 1;
	wc = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (b == 1)
			{
				wc += 1;
				b = 0;
			}
		}
		else
			b = 1;
		s++;
	}
	return (wc);
}

static size_t	ft_strnlen(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void	ft_freetab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static char	**fill_split(const char *s, char c, char **tab)
{
	int	l;
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			l = ft_strnlen(s, c);
			tab[i] = ft_calloc(l + 1, sizeof(char));
			if (tab[i] == NULL)
			{
				ft_freetab(tab, i - 1);
				return (NULL);
			}
			ft_strlcpy(tab[i], s, l + 1);
			i++;
			s += l;
		}
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab = fill_split(s, c, tab);
	return (tab);
}
