/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:05:25 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/17 15:00:44 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_accu	*accu[1024];
	char			*return_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!accu[fd])
		accu[fd] = NULL;
	return_line = make_line(fd, &accu[fd]);
	if (return_line == NULL || return_line[0] == '\0')
	{
		if (return_line != NULL)
			free(return_line);
		gnl_lstclear(&accu[fd]);
		return (NULL);
	}
	if (accu[fd] != NULL && accu[fd]->content[0] == '\0')
		gnl_lstclear(&accu[fd]);
	return (return_line);
}
