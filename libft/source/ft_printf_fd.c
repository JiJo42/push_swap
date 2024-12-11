/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:26:24 by jijo              #+#    #+#             */
/*   Updated: 2024/12/11 13:15:13 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_fd_dir/ft_printffd.h"

static int	ft_makeformat(int fd, va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_pffd(fd, va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_pffd(fd, va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putadress_pffd(fd, va_arg(args, unsigned long int),
				"0123456789abcdef"));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_pffd(fd, va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned_pffd(fd, va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_pffd(fd, va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex_pffd(fd, va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_pffd(fd, '%'));
	else
	{
		ft_putstr_pffd(2, "\n\n!Error!   undefined format for : %");
		write(2, &c, 1);
		return (-1);
	}
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		size;
	int		tmp;

	if (!format)
		return (-1);
	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = ft_makeformat(fd, args, *format);
			if (tmp == -1)
				return (-1);
			size += tmp;
		}
		else
			size += ft_putchar_pffd(fd, *format);
		format++;
	}
	va_end(args);
	return (size);
}
