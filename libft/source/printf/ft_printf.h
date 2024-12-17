/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:39:07 by dleclerc          #+#    #+#             */
/*   Updated: 2024/11/15 19:45:43 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar_pf(char c);
int		ft_putstr_pf(const char *s);
void	ft_putstr_error(const char *s);
int		ft_putnbr_pf(int nbr);
int		ft_putnbr_unsigned_pf(unsigned int nbr);
int		ft_puthex_pf(unsigned int nbr, char *base);
int		ft_putadress_pf(unsigned long int nbr, char *base);

#endif