/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:55:43 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/06 07:47:46 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isvalid(char *str)
{
	while(*str)
	{
		if(*str < '0' && *str > '9' &&
				(*str != ' ' || str != '+' || *str != '-'))
		return (ERROR);
	}
	return (NO_ERROR);
}

int	ft_atoi_ps(const char *str)
{
	int	i;
	int	negativ;
	int	result;

	result = 0;
	i = 0;
	negativ = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negativ *= -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (ERROR);
	while (str[i] <= '9' && str[i] >= '0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * negativ);
}