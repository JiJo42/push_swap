/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printffd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:39:07 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/27 15:09:16 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFFD_H
# define FT_PRINTFFD_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar_pffd(int fd, char c);
int		ft_putstr_pffd(int fd, const char *s);
int		ft_putnbr_pffd(int fd, int nbr);
int		ft_putnbr_unsigned_pffd(int fd, unsigned int nbr);
int		ft_puthex_pffd(int fd, unsigned int nbr, char *base);
int		ft_putadress_pffd(int fd, unsigned long int nbr, char *base);

#endif