/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_fix_for_pipex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:54:53 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/15 19:59:43 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_split_last(t_accu **accu, t_accu *last, char *return_line)
{
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (return_line[size] != '\0')
		size++;
	while (last->content[i] != '\0' && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		size++;
	tmp = malloc(size + i + 1 * sizeof(char));
	if (tmp == NULL)
	{
		free (return_line);
		return (NULL);
	}
	tmp[0] = '\0';
	ft_strlcat(tmp, return_line, size + i + 1);
	free (return_line);
	ft_strlcat(tmp, last->content, size + i + 1);
	if (gnl_lstnew_save(accu, last->content, i) == -1)
		return (NULL);
	return (tmp);
}

char	*gnl_create_line(t_accu **accu)
{
	char	*return_line;
	int		size;
	t_accu	*tmp;

	tmp = *accu;
	size = 0;
	while (tmp->next != NULL)
	{
		size += BUFFER_SIZE;
		tmp = tmp->next;
	}
	return_line = malloc((size + 1) * sizeof(char));
	if (return_line == NULL)
		return (NULL);
	return_line[0] = '\0';
	tmp = *accu;
	while (tmp->next != NULL)
	{
		ft_strlcat(return_line, tmp->content, size + 1);
		tmp = tmp->next;
	}
	return_line = gnl_split_last(accu, tmp, return_line);
	if (return_line == NULL)
		return (NULL);
	return (return_line);
}

int	gnl_find_line(t_accu **accu, int fd, int file_return)
{
	t_accu	*new;

	new = *accu;
	file_return = BUFFER_SIZE;
	if (*accu == NULL)
	{
		new = gnl_lstnew(BUFFER_SIZE);
		if (new != NULL)
		{
			file_return = read(fd, new->content, BUFFER_SIZE);
			gnl_lstadd_back(accu, new);
		}
	}
	while (!(gnl_strchr(new->content, '\n')) && file_return > 0 && new != NULL)
	{
		new = gnl_lstnew(BUFFER_SIZE);
		if (new != NULL)
		{
			file_return = read(fd, new->content, BUFFER_SIZE);
			gnl_lstadd_back(accu, new);
		}
	}
	if (new == NULL)
		return (-1);
	return (file_return);
}

t_accu	*gnl_lstnew(int size)
{
	t_accu	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = malloc(size + 1 * sizeof(char));
	if (new_elem->content == NULL)
		return (NULL);
	new_elem->next = NULL;
	while (size >= 0)
	{
		new_elem->content[size] = 0;
		size--;
	}
	return (new_elem);
}

char	*make_line(int fd, t_accu **accu)
{
	int		file_return;
	char	*return_line;

	file_return = 0;
	file_return = gnl_find_line(accu, fd, file_return);
	if (file_return < 0)
	{
		gnl_lstclear(accu);
		*accu = NULL;
		return (NULL);
	}
	return_line = NULL;
	return_line = gnl_create_line(accu);
	return (return_line);
}
