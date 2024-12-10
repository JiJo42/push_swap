/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:19:54 by dleclerc          #+#    #+#             */
/*   Updated: 2024/12/09 10:42:41 by dleclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	negativ;
	int	result;

	result = 0;
	i = 0;
	negativ = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negativ *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * negativ);
}
