/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:05:58 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/08 15:29:11 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_lstclear(t_accu **lst)
{
	t_accu	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			if ((*lst)->content != NULL)
				free((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	gnl_lstadd_back(t_accu **lst, t_accu *new)
{
	t_accu	*last;

	if (lst)
	{
		last = *lst;
		if (!last)
			*lst = new;
		else
		{
			while (last->next != NULL)
				last = last->next;
			last->next = new;
		}
	}
}

int	gnl_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return (1);
	return (0);
}

int	gnl_lstnew_save(t_accu **accu, char *str, int i)
{
	int		j;
	int		size;
	t_accu	*new;

	j = 0;
	size = 0;
	while (str[size] != '\0')
		size++;
	if (str[i] == '\n')
	{
		new = gnl_lstnew(size - i);
		if (new == NULL)
			return (-1);
		i++;
		while (str[i + j] != '\0')
		{
			(new->content)[j] = str[i + j];
			j++;
		}
		gnl_lstclear(accu);
		gnl_lstadd_back(accu, new);
	}
	else
		gnl_lstclear(accu);
	return (1);
}
