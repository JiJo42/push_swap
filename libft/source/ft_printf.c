/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:26:24 by jijo              #+#    #+#             */
/*   Updated: 2024/12/11 13:15:03 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_dir/ft_printf.h"

static int	ft_makeformat(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putadress_pf(va_arg(args, unsigned long int),
				"0123456789abcdef"));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned_pf(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_pf(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex_pf(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_pf('%'));
	else
	{
		ft_putstr_error("\n\n!Error!   undefined format for : %");
		write(2, &c, 1);
		return (-1);
	}
}

int	ft_printf(const char *format, ...)
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
			tmp = ft_makeformat(args, *format);
			if (tmp == -1)
				return (-1);
			size += tmp;
		}
		else
			size += ft_putchar_pf(*format);
		format++;
	}
	va_end(args);
	return (size);
}
