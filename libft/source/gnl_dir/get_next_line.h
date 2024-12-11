/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:06:14 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/15 19:45:51 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_accu
{
	char			*content;
	struct s_accu	*next;
}	t_accu;

void	gnl_lstclear(t_accu **lst);
t_accu	*gnl_lstlast(t_accu *lst);
void	gnl_lstadd_back(t_accu **lst, t_accu *new);
int		gnl_strchr(const char *s, int c);
int		gnl_lstnew_save(t_accu **accu, char *str, int i);
t_accu	*gnl_lstnew(int size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*make_line(int fd, t_accu **accu);
int		gnl_find_line(t_accu **accu, int fd, int file_return);
char	*gnl_split_last(t_accu **accu, t_accu *last, char *return_line);
char	*gnl_create_line(t_accu **accu);

#endif